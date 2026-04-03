#include <iostream>
#include <locale.h>

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
    day dd;
    month mm;
    year yyyy;
};

bool operator < (const Date& d1, const Date& d2) {
    if (d1.yyyy < d2.yyyy) return true;
    if (d1.yyyy > d2.yyyy) return false;
    if (d1.mm < d2.mm) return true;
    if (d1.mm > d2.mm) return false;
    return d1.dd < d2.dd;
}

bool operator > (const Date& d1, const Date& d2) {
    if (d1.yyyy > d2.yyyy) return true;
    if (d1.yyyy < d2.yyyy) return false;
    if (d1.mm > d2.mm) return true;
    if (d1.mm < d2.mm) return false;
    return d1.dd > d2.dd;
}

bool operator == (const Date& d1, const Date& d2) {
    return (d1.dd == d2.dd && d1.mm == d2.mm && d1.yyyy == d2.yyyy);
}


int main() {
    setlocale(LC_ALL, "rus");

    Date date1 = {7, 1, 1980};
    Date date2 = {7, 2, 1993};
    Date date3 = {7, 1, 1980};

    if (date1 < date2) std::cout << "истина" << std::endl;
    else std::cout << "ложь" << std::endl;

    if (date1 > date2) std::cout << "истина" << std::endl;
    else std::cout << "ложь" << std::endl;

    if (date1 == date2) std::cout << "истина" << std::endl;
    else std::cout << "ложь" << std::endl;

    if (date1 == date3) std::cout << "истина" << std::endl;
    else std::cout << "ложь" << std::endl;

    return 0;
}
