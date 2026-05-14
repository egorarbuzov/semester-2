#include "stdafx.h"
#include "isYearVis.h"

int dayNumber(int month, int day, int* days) {
    int dayNumber = 0;
    for (int i = 0; i < month - 1; i++) {
        dayNumber += days[i];
    }
    dayNumber += day;
    return dayNumber;
}
