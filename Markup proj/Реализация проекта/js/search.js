// БАЗА ДАННЫХ АВИАБИЛЕТОВ (простые понятные ключи)
const flightsDatabase = [
    {
        from: "Москва",
        to: "Сочи",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 1111", departure: "07:00", arrival: "09:45", duration: "2ч 45м", price: 8900, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 2222", departure: "11:30", arrival: "14:15", duration: "2ч 45м", price: 7600, baggage: true, meal: true, wifi: false },
            { airline: "Победа", flightNo: "DP 4444", departure: "20:30", arrival: "23:15", duration: "2ч 45м", price: 4200, baggage: false, meal: false, wifi: false }
        ]
    },
    {
        from: "Москва",
        to: "Санкт-Петербург",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 1234", departure: "08:00", arrival: "09:30", duration: "1ч 30м", price: 4500, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 5678", departure: "12:00", arrival: "13:30", duration: "1ч 30м", price: 3800, baggage: true, meal: false, wifi: false },
            { airline: "Победа", flightNo: "DP 9012", departure: "18:30", arrival: "20:00", duration: "1ч 30м", price: 2500, baggage: false, meal: false, wifi: false }
        ]
    },
    {
        from: "Москва",
        to: "Екатеринбург",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 1400", departure: "09:00", arrival: "13:30", duration: "2ч 30м", price: 7200, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 2500", departure: "14:00", arrival: "18:30", duration: "2ч 30м", price: 5900, baggage: true, meal: false, wifi: false },
            { airline: "Уральские авиалинии", flightNo: "U6 3600", departure: "19:00", arrival: "23:30", duration: "2ч 30м", price: 4800, baggage: true, meal: false, wifi: false }
        ]
    },
    {
        from: "Москва",
        to: "Казань",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 1190", departure: "08:30", arrival: "10:00", duration: "1ч 30м", price: 5500, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 1191", departure: "13:00", arrival: "14:30", duration: "1ч 30м", price: 4600, baggage: true, meal: false, wifi: false },
            { airline: "Победа", flightNo: "DP 1192", departure: "18:00", arrival: "19:30", duration: "1ч 30м", price: 3200, baggage: false, meal: false, wifi: false }
        ]
    },
    {
        from: "Москва",
        to: "Новосибирск",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 1460", departure: "09:00", arrival: "17:00", duration: "4ч 00м", price: 12500, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 1461", departure: "14:00", arrival: "22:00", duration: "4ч 00м", price: 10800, baggage: true, meal: true, wifi: false },
            { airline: "Уральские авиалинии", flightNo: "U6 1462", departure: "20:00", arrival: "04:00", duration: "4ч 00м", price: 8900, baggage: true, meal: false, wifi: false }
        ]
    },
    {
        from: "Санкт-Петербург",
        to: "Москва",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 4321", departure: "09:30", arrival: "11:00", duration: "1ч 30м", price: 4800, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 8765", departure: "13:30", arrival: "15:00", duration: "1ч 30м", price: 4100, baggage: true, meal: false, wifi: false },
            { airline: "Победа", flightNo: "DP 1098", departure: "19:00", arrival: "20:30", duration: "1ч 30м", price: 2800, baggage: false, meal: false, wifi: false }
        ]
    },
    {
        from: "Сочи",
        to: "Москва",
        flights: [
            { airline: "Аэрофлот", flightNo: "SU 5555", departure: "10:30", arrival: "13:15", duration: "2ч 45м", price: 9200, baggage: true, meal: true, wifi: true },
            { airline: "S7 Airlines", flightNo: "S7 6666", departure: "15:00", arrival: "17:45", duration: "2ч 45м", price: 7900, baggage: true, meal: true, wifi: false },
            { airline: "Уральские авиалинии", flightNo: "U6 7777", departure: "19:30", arrival: "22:15", duration: "2ч 45м", price: 6800, baggage: true, meal: false, wifi: false }
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

// ПОИСК БИЛЕТОВ (простой перебор)
function searchFlights(from, to) {
    // Убираем лишние пробелы
    const searchFrom = from.trim();
    const searchTo = to.trim();
    
    console.log("Ищем:", searchFrom, "→", searchTo);
    
    // Перебираем все маршруты в базе
    for (let i = 0; i < flightsDatabase.length; i++) {
        const route = flightsDatabase[i];
        // Сравниваем (без учета регистра)
        if (route.from.toLowerCase() === searchFrom.toLowerCase() && 
            route.to.toLowerCase() === searchTo.toLowerCase()) {
            console.log("Найден маршрут:", route);
            return route;
        }
    }
    
    console.log("Маршрут не найден");
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
        <div class="flight-card" onclick="selectFlight('${flight.airline}', '${flight.flightNo}', ${flight.price})">
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
                        <span>•</span>
                        <i class="fas fa-tag"></i>
                        <span>${flight.airline} ${flight.flightNo}</span>
                    </div>
                </div>
            </div>
            <div class="flight-details">
                ${flight.baggage ? '<div class="detail-badge"><i class="fas fa-suitcase"></i> багаж</div>' : '<div class="detail-badge"><i class="fas fa-suitcase" style="opacity:0.3"></i> без багажа</div>'}
                ${flight.meal ? '<div class="detail-badge"><i class="fas fa-utensils"></i> питание</div>' : ''}
                ${flight.wifi ? '<div class="detail-badge"><i class="fas fa-wifi"></i> Wi-Fi</div>' : ''}
                <div class="detail-badge"><i class="fas fa-check-circle"></i> прямой</div>
            </div>
            <div class="flight-action">
                <div class="price">
                    <i class="fas fa-ruble-sign"></i> ${flight.price.toLocaleString()}
                </div>
                <button class="select-btn" onclick="event.stopPropagation(); selectFlight('${flight.airline}', '${flight.flightNo}', ${flight.price})">
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
                <ul style="margin-top: 0.5rem; list-style: none;">
                    <li>• Москва → Сочи</li>
                    <li>• Москва → Санкт-Петербург</li>
                    <li>• Москва → Екатеринбург</li>
                    <li>• Москва → Казань</li>
                    <li>• Москва → Новосибирск</li>
                    <li>• Санкт-Петербург → Москва</li>
                    <li>• Сочи → Москва</li>
                </ul>
            </div>
        `;
    }
    const pageNumbers = document.getElementById('pageNumbers');
    if (pageNumbers) pageNumbers.innerHTML = '';
}

// ВЫБОР БИЛЕТА
function selectFlight(airline, flightNo, price) {
    alert(`Вы выбрали рейс ${airline} ${flightNo}\nСтоимость: ${price.toLocaleString()} ₽\n\nФункция бронирования будет доступна в следующей версии.`);
}

// ГЛАВНАЯ ФУНКЦИЯ
function init() {
    const params = getSearchParams();
    const { from, to, date, passengers } = params;
    
    console.log("Параметры:", { from, to, date, passengers });
    
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