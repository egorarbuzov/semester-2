#include <iostream>

using namespace std;

void function1() {

}

int function2(int a) {
    return a;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n = 1;
    short X = 9 + n;
    int Y = 10 + n;
    int Z = 11 + n;
    float S = 1.0 + n;

    bool first = false; // false
    bool second = true;// true

    char letter = 'r'; // char 'r' , 0x16fdfee35
    
    wchar_t large_letter = L'A'; // wchar_t L'A', 0x16fdfee2c
    wchar_t large_ru_letter = L'A'; // wchar_t L'?', 0x16fdfee28

    short short_positive = X; // 0x000A
    short short_negative = -X; // 0xFFF6

    short max_short = 0x7FFF; // 32767
    short min_short = 0x8000; // -32768

    unsigned short max_ushort = 0xFFFF; // 65535
    unsigned short min_ushort = 0x0000; // 0

    int int_positive = Y; // 0xB
    int int_negative = -Y; // 0xF5

    int max_int = 0x7FFFFFFF; // 2147483647
    int min_int = 0x80000000; // -2147483648

    unsigned int max_uint = 0xFFFFFFFF; // 4294967295
    unsigned int min_uint = 0x00000000; // 0

    long long1 = Z; // 0xC
    long long2 = -Z; // 0xF4

    long max_long = 0x7FFFFFFF; // 2147483647
    long min_long = 0x80000000; // -2147483648

    unsigned long max_ulong = 0xFFFFFFFF; // 4294967295
    unsigned long min_ulong = 0x00000000; // 0

    float float1 = S; // 0x40000000
    float float2 = -S; // 0xc0000000


    float inf_pos = exp(1000.0f);
    float inf_neg = log(0.0f);
    float ind = sqrt(-1.0f);

    char* p_char = &letter; // 0x72
    short* p_short = &short_positive; // 0x16fdfee26
    int* p_int = &int_positive; // 0x1fab66960
    float* p_float = &float1; // 0x16fdfedcc
    double* p_double = nullptr;
    double d = 3.14;
    p_double = &d; //0x16fdfed80

    p_char += 3;
    p_short += 3;
    p_int += 3;
    p_float += 3;
    p_double += 3;

    char& r_char = letter;//0x000000016fdfee35
    short& r_short = short_positive;//0x000000016fdfee26
    int& r_int = int_positive;// 0x000000016fdfee18
    float& r_float = float1; // 0x000000016fdfedcc
    double& r_double = d; // 0x000000016fdfed80

    void (*func1)() = &function1;
    int (*func2)(int) = &function2;


    return 0;
}
