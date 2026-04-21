#include "Call.h"

int __cdecl cdecl(int a, int b, int c) {
    return a + b + c;
}

int __stdcall cstd(int& a, int b, int c) {
    return a * b * c;
}

int __fastcall csft(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main() {
    std::cout << cdecl(1, 2, 3) << std::endl;
    int link = 2;
    std::cout << cstd(link, 2, 3) << std::endl;
    std::cout << csft(1, 2, 3, 4) << std::endl;
    
    return 0;
}

