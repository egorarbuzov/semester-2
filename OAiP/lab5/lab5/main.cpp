#include <iostream>
#include "mylib.h"

using namespace std;

int main() {
    char test = 'a';
    cout << test << endl;
    cout << toUp(test) << endl;
    cout << endl;
    char str[] = "hello";
    cout << reverseString(str) << endl;
    cout << endl;
    char strstr[] = "hello world";
    char substr[20];
    cout << getSubStr(strstr, 5, 5, substr) << endl;
    cout << endl;
    char subsubstr[] = "world";
    cout << findSubIndex(strstr, subsubstr) << endl;
    cout << endl;
    return 0;
}
