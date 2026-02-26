#include "stdafx.h"
#include "dayNumber.h"

bool isYearVis(int year) {
    if (year % 400 == 0 || year % 4 == 0) return true;
    return false;
}
