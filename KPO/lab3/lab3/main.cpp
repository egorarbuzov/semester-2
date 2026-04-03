#include "stdafx.h"
#include "isYearVis.h"
#include "dayNumber.h"
#include "monthsFunc.h"

bool isValidDate(int day, int month, int year, const int daysInMonth[]) {
    if (year < 0) return false;
    
    if (month < 1 || month > 12) return false;
    
    if (day < 1 || day > daysInMonth[month - 1]) return false;
    
    return true;
}

int main() {
    int day = 0, month = 0, year = 0;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string months[12] = { "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };
    
    cout << "Введите дату в формате ДДММГГГГ: ";
    scanf("%2d%2d%4d", &day, &month, &year);
    
    if (isYearVis(year)) {
        days[1] = 29;
    }

    if (!isValidDate(day, month, year, days)) {
        cout << "Ошибка! Введена некорректная дата." << endl;
        return 1;
    }
    
    
    cout << "Вы ввели: " << day << " " << month << " " << year << endl;
    cout << "Название введенного месяца: " << getMonth(month, months) << endl; // для 3 лабы (месяц)
    
    if (isYearVis(year)) {
        cout << "Год является високосным" << endl;
    } else {
        cout << "Год НЕ является високосным" << endl;
    }
    
    cout << "Количество дней в году: " << dayNumber(month, day, days) << endl;
    
    int birthday_day, birthday_month;
    cout << "Введите дату вашего рождения в формате ДДММ: ";
    scanf("%2d%2d", &birthday_day, &birthday_month);
    
    if (!isValidDate(birthday_day, birthday_month, 2000, days)) {
        cout << "Ошибка! Введена некорректная дата рождения." << endl;
        return 1;
    }
    
    int daysToBirthday;
    int todayNumber = dayNumber(month, day, days);
    int birthdayThisYear = dayNumber(birthday_month, birthday_day, days);
    
    if (birthdayThisYear > todayNumber) {
        daysToBirthday = birthdayThisYear - todayNumber;
        cout << "День рождения будет в этом году через " << daysToBirthday << " дней" << endl;
    }
    else if (birthdayThisYear < todayNumber) {
        int daysInCurrentYear = 365;
        if (isYearVis(year)) {
            daysInCurrentYear = 366;
        }
        daysToBirthday = (daysInCurrentYear - todayNumber) + birthdayThisYear;
        cout << "День рождения будет в следующем году через " << daysToBirthday << " дней" << endl;
    }
    
    int dayNum = 0; // определение дня в году (3 лаба)
    int result[2];
    cout << "Введите номер дня в году: "; cin >> dayNum;
    getDateByNumber(dayNum, days, result);
    cout << "Дата: " << result[0] << " " << months[result[1] - 1] << endl;
    
    
    return 0;
}

