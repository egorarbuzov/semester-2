#include "stdafx.h"
#include "funcs.h"

int main() {
    int day = 0, month = 0, year = 0;
    bool okey = false;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (okey == false) {
        cout << "Введите дату в формате ДДММГГГГ: ";
        scanf("%2d%2d%4d", &day, &month, &year);

        
        if (year < 0) {
            okey = false;
            cout << "Ошибка, год меньше 0" << endl;
            continue;
        }
        
        if (month < 1 || month > 12) {
            okey = false;
            cout << "Ошибка, неккоректное знаение месяца!" << endl;
            continue;
        }
        
        int dayinmonth = days[month - 1];
        
        if (day < 1 || day > dayinmonth) {
            okey = false;
            cout << "Ошибка, неккоректное количество дней в месяце!" << endl;
            continue;
        }
        
        okey = true;
    }
    cout << "Вы ввели: " << day << " " << month << " " << year << endl;
    
    if (isYearVis(year)) {
        cout << "Год является високосным" << endl;
    } else {
        cout << "Год НЕ является високосным" << endl;
    }
    
    cout << "Количество дней в году: " << dayNumber(month, day, days) << endl;
    
    int birthday_day = 0, birthday_month = 0;
    cout << "Введите дату вашего рождения в формате ДДММ: ";
    scanf("%2d%2d", &birthday_day, &birthday_month);
    int birthday_delta = abs(dayNumber(birthday_month, birthday_day, days) - dayNumber(month, day, days));
    cout << birthday_delta << endl;
    
    return 0;
}
