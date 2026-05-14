#include "stdafx.h"
#include "monthsFunc.h"

string getMonth(int month, string* months) {
    int index = month - 1;
    return months[index];
}
