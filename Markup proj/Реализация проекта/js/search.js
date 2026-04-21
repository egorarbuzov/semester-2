// БАЗА ДАННЫХ АВИАБИЛЕТОВ (упрощенная)
const flightsDatabase = [
    // Внутренние рейсы по Беларуси
    {
        from: "Минск",
        to: "Брест",
        flights: [
            { departure: "08:00", arrival: "08:45", duration: "45м", price: 89 },
            { departure: "14:30", arrival: "15:15", duration: "45м", price: 79 },
            { departure: "19:00", arrival: "19:45", duration: "45м", price: 69 }
        ]
    },
    {
        from: "Минск",
        to: "Гродно",
        flights: [
            { departure: "09:15", arrival: "10:10", duration: "55м", price: 92 },
            { departure: "16:00", arrival: "16:55", duration: "55м", price: 82 },
            { departure: "20:30", arrival: "21:25", duration: "55м", price: 72 }
        ]
    },
    {
        from: "Минск",
        to: "Гомель",
        flights: [
            { departure: "07:30", arrival: "08:20", duration: "50м", price: 85 },
            { departure: "13:00", arrival: "13:50", duration: "50м", price: 75 },
            { departure: "18:30", arrival: "19:20", duration: "50м", price: 65 }
        ]
    },
    {
        from: "Минск",
        to: "Могилев",
        flights: [
            { departure: "10:00", arrival: "10:40", duration: "40м", price: 75 },
            { departure: "15:30", arrival: "16:10", duration: "40м", price: 65 }
        ]
    },
    {
        from: "Минск",
        to: "Витебск",
        flights: [
            { departure: "11:30", arrival: "12:25", duration: "55м", price: 88 },
            { departure: "17:00", arrival: "17:55", duration: "55м", price: 78 }
        ]
    },
    // Международные рейсы
    {
        from: "Минск",
        to: "Москва",
        flights: [
            { departure: "07:00", arrival: "08:45", duration: "1ч 45м", price: 145 },
            { departure: "12:30", arrival: "14:15", duration: "1ч 45м", price: 135 },
            { departure: "18:00", arrival: "19:45", duration: "1ч 45м", price: 125 }
        ]
    },
    {
        from: "Минск",
        to: "Варшава",
        flights: [
            { departure: "08:30", arrival: "09:30", duration: "1ч 00м", price: 98 },
            { departure: "14:00", arrival: "15:00", duration: "1ч 00м", price: 88 },
            { departure: "19:30", arrival: "20:30", duration: "1ч 00м", price: 78 }
        ]
    },
    // Обратные рейсы
    {
        from: "Брест",
        to: "Минск",
        flights: [
            { departure: "09:15", arrival: "10:00", duration: "45м", price: 89 },
            { departure: "15:45", arrival: "16:30", duration: "45м", price: 79 }
        ]
    },
    {
        from: "Гродно",
        to: "Минск",
        flights: [
            { departure: "10:40", arrival: "11:35", duration: "55м", price: 92 },
            { departure: "17:20", arrival: "18:15", duration: "55м", price: 82 }
        ]
    },
    {
        from: "Гомель",
        to: "Минск",
        flights: [
            { departure: "08:50", arrival: "09:40", duration: "50м", price: 85 },
            { departure: "14:20", arrival: "15:10", duration: "50м", price: 75 }
        ]
    },
    {
        from: "Москва",
        to: "Минск",
        flights: [
            { departure: "09:30", arrival: "11:15", duration: "1ч 45м", price: 145 },
            { departure: "15:00", arrival: "16:45", duration: "1ч 45м", price: 135 },
            { departure: "20:30", arrival: "22:15", duration: "1ч 45м", price: 125 }
        ]
    },
    {
        from: "Варшава",
        to: "Минск",
        flights: [
            { departure: "10:00", arrival: "11:00", duration: "1ч 00м", price: 98 },
            { departure: "15:30", arrival: "16:30", duration: "1ч 00м", price: 88 },
            { departure: "21:00", arrival: "22:00", duration: "1ч 00м", price: 78 }
        ]
    }
];

// ПОЛУЧАЕМ ПАРАМЕТРЫ ИЗ URL
function getSearchParams() {
    const urlParams = new URLSearchParams(window.location.search);
    return {
        from: urlParams.get('from') || '',
        to: urlParams.get('to') || '',
        date: urlParams.get('date') || '',
        passengers: urlParams.get('passengers') || '1'
    };
}

// ПОИСК БИЛЕТОВ
function searchFlights(from, to) {
    const searchFrom = from.trim();
    const searchTo = to.trim();
    
    for (let i = 0; i < flightsDatabase.length; i++) {
        const route = flightsDatabase[i];
        if (route.from.toLowerCase() === searchFrom.toLowerCase() && 
            route.to.toLowerCase() === searchTo.toLowerCase()) {
            return route;
        }
    }
    return null;
}

// ОТОБРАЖЕНИЕ ИНФОРМАЦИИ О ПОИСКЕ
function renderSearchInfo(from, to, date, passengers, flightsCount) {
    const searchInfo = document.getElementById('searchInfo');
    if (!searchInfo) return;
    
    searchInfo.innerHTML = `
        <div class="search-params">
            <div class="search-param">
                <i class="fas fa-map-marker-alt"></i>
                <span>${escapeHtml(from)}</span>
                <i class="fas fa-arrow-right" style="color: #8a2c2d;"></i>
                <span>${escapeHtml(to)}</span>
            </div>
            <div class="search-param">
                <i class="far fa-calendar-alt"></i>
                <span>${escapeHtml(date || 'дата не указана')}</span>
            </div>
            <div class="search-param">
                <i class="fas fa-user-friends"></i>
                <span>${escapeHtml(passengers)} пассажир(ов)</span>
            </div>
        </div>
        <div class="results-count">
            <i class="fas fa-plane"></i> Найдено <span>${flightsCount}</span> рейсов
        </div>
    `;
}

// ЭКРАНИРОВАНИЕ HTML
function escapeHtml(str) {
    if (!str) return '';
    return str
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;')
        .replace(/"/g, '&quot;')
        .replace(/'/g, '&#39;');
}

// ОТОБРАЖЕНИЕ СПИСКА БИЛЕТОВ
function renderFlights(routeData, currentPage, itemsPerPage) {
    const flightsList = document.getElementById('flightsList');
    if (!flightsList) return;
    
    const flights = routeData.flights;
    const totalPages = Math.ceil(flights.length / itemsPerPage);
    
    const start = (currentPage - 1) * itemsPerPage;
    const end = start + itemsPerPage;
    const currentFlights = flights.slice(start, end);
    
    if (currentFlights.length === 0) {
        flightsList.innerHTML = '<div class="empty-result"><i class="fas fa-search"></i><p>Нет рейсов на выбранную дату</p></div>';
        return;
    }
    
    flightsList.innerHTML = currentFlights.map(flight => `
        <div class="flight-card" onclick="selectFlight(${flight.price}, '${flight.departure}', '${flight.arrival}')">
            <div class="flight-info">
                <div class="airline-icon">
                    <i class="fas fa-plane"></i>
                </div>
                <div class="route-info">
                    <div class="route">
                        <div class="from-to">
                            <i class="fas fa-map-marker-alt"></i>
                            <span class="city">${escapeHtml(routeData.from)}</span>
                        </div>
                        <i class="fas fa-arrow-right arrow"></i>
                        <div class="from-to">
                            <i class="fas fa-location-dot"></i>
                            <span class="city">${escapeHtml(routeData.to)}</span>
                        </div>
                    </div>
                    <div class="time">
                        <i class="far fa-clock"></i>
                        <span>${flight.departure} → ${flight.arrival}</span>
                        <span>•</span>
                        <i class="fas fa-hourglass-half"></i>
                        <span>${flight.duration}</span>
                    </div>
                </div>
            </div>
            <div class="flight-action">
                <div class="price">
                   ${flight.price.toLocaleString()} BYN 
                </div>
                <button class="select-btn" onclick="event.stopPropagation(); selectFlight(${flight.price}, '${flight.departure}', '${flight.arrival}')">
                    <i class="fas fa-check-circle"></i> Выбрать
                </button>
            </div>
        </div>
    `).join('');
    
    renderPagination(currentPage, totalPages);
}

// ПАГИНАЦИЯ
function renderPagination(currentPage, totalPages) {
    const pageNumbers = document.getElementById('pageNumbers');
    if (!pageNumbers) return;
    
    if (totalPages <= 1) {
        pageNumbers.innerHTML = '';
        return;
    }
    
    let pagesHtml = '';
    for (let i = 1; i <= totalPages; i++) {
        pagesHtml += `<div class="page-number ${i === currentPage ? 'active' : ''}" data-page="${i}">${i}</div>`;
    }
    pageNumbers.innerHTML = pagesHtml;
    
    document.querySelectorAll('.page-number').forEach(el => {
        el.addEventListener('click', () => {
            const page = parseInt(el.dataset.page);
            const params = getSearchParams();
            window.location.href = `search.html?from=${encodeURIComponent(params.from)}&to=${encodeURIComponent(params.to)}&date=${encodeURIComponent(params.date)}&passengers=${encodeURIComponent(params.passengers)}&page=${page}`;
        });
    });
}

// ПУСТОЙ РЕЗУЛЬТАТ
function showEmptyResult(from, to) {
    const flightsList = document.getElementById('flightsList');
    if (flightsList) {
        flightsList.innerHTML = `
            <div class="empty-result">
                <i class="fas fa-search"></i>
                <p>По вашему запросу "${escapeHtml(from)} → ${escapeHtml(to)}" ничего не найдено</p>
                <p style="font-size: 0.85rem; margin-top: 0.5rem;">Доступные направления:</p>
                <ul style="margin-top: 0.5rem; list-style: none; text-align: left; display: inline-block;">
                    <li>• Минск → Брест</li>
                    <li>• Минск → Гродно</li>
                    <li>• Минск → Гомель</li>
                    <li>• Минск → Могилев</li>
                    <li>• Минск → Витебск</li>
                    <li>• Минск → Москва</li>
                    <li>• Минск → Варшава</li>
                    <li>• Брест → Минск</li>
                    <li>• Гродно → Минск</li>
                    <li>• Гомель → Минск</li>
                    <li>• Москва → Минск</li>
                    <li>• Варшава → Минск</li>
                </ul>
            </div>
        `;
    }
    const pageNumbers = document.getElementById('pageNumbers');
    if (pageNumbers) pageNumbers.innerHTML = '';
}

// ВЫБОР БИЛЕТА
function selectFlight(price, departure, arrival) {
    alert(`✈️ Вы выбрали рейс\n🕐 Вылет: ${departure}\n🕐 Прилет: ${arrival}\n💰 Стоимость: ${price.toLocaleString()} BYN\n\nФункция бронирования будет доступна в следующей версии.`);
}

// ГЛАВНАЯ ФУНКЦИЯ
function init() {
    const params = getSearchParams();
    const { from, to, date, passengers } = params;
    
    if (!from || !to) {
        showEmptyResult('?', '?');
        const searchInfo = document.getElementById('searchInfo');
        if (searchInfo) {
            searchInfo.innerHTML = '<div class="empty-result" style="padding: 1rem;"><i class="fas fa-exclamation-triangle"></i><p>Пожалуйста, укажите маршрут на главной странице</p></div>';
        }
        return;
    }
    
    const routeData = searchFlights(from, to);
    
    if (!routeData) {
        showEmptyResult(from, to);
        renderSearchInfo(from, to, date, passengers, 0);
        return;
    }
    
    const currentPage = parseInt(new URLSearchParams(window.location.search).get('page')) || 1;
    const itemsPerPage = 5;
    
    renderSearchInfo(routeData.from, routeData.to, date, passengers, routeData.flights.length);
    renderFlights(routeData, currentPage, itemsPerPage);
}

// ЗАПУСК
document.addEventListener('DOMContentLoaded', () => {
    init();
    
    const prevBtn = document.getElementById('prevPage');
    const nextBtn = document.getElementById('nextPage');
    
    if (prevBtn) {
        prevBtn.addEventListener('click', () => {
            const params = getSearchParams();
            let currentPage = parseInt(new URLSearchParams(window.location.search).get('page')) || 1;
            if (currentPage > 1) {
                window.location.href = `search.html?from=${encodeURIComponent(params.from)}&to=${encodeURIComponent(params.to)}&date=${encodeURIComponent(params.date)}&passengers=${encodeURIComponent(params.passengers)}&page=${currentPage - 1}`;
            }
        });
    }
    
    if (nextBtn) {
        nextBtn.addEventListener('click', () => {
            const params = getSearchParams();
            let currentPage = parseInt(new URLSearchParams(window.location.search).get('page')) || 1;
            const routeData = searchFlights(params.from, params.to);
            const totalPages = routeData ? Math.ceil(routeData.flights.length / 5) : 1;
            if (currentPage < totalPages) {
                window.location.href = `search.html?from=${encodeURIComponent(params.from)}&to=${encodeURIComponent(params.to)}&date=${encodeURIComponent(params.date)}&passengers=${encodeURIComponent(params.passengers)}&page=${currentPage + 1}`;
            }
        });
    }
});