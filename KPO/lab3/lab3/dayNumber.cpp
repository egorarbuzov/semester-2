#include "stdafx.h"

int dayNumber(int month, int day, int* days) {
    int dayNumber = 0;
    for (int i = 0; i < month - 1; i++) {
        dayNumber += days[i];
    }
    dayNumber += day;
    return dayNumber;
}

void getDateByNumber(int daynum, int* daysInMonths, int* output) {
    int remaining_days = daynum;
    int month = 0;
    
    if (daynum < 1 || daynum > 365) {
        output[0] = -1;
        output[1] = -1;
        return;
    }
    while (remaining_days > daysInMonths[month]) {
        remaining_days -= daysInMonths[month];
        month++;
    }
    
    output[0] = remaining_days;
    output[1] = month + 1;
}
