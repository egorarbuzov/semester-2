#include <iostream>

using namespace std;

char toUp(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    } else return c;
}

char* reverseString(char* string) {
    int length = 0;

    while (string[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }
    return string;
}

char* getSubStr(char* str, int start, int length, char* substr) {
    for (int i = 0; i < length; i++) {
        substr[i] = str[start + i];
    }
    substr[length] = '\0';
    return substr;
}

int findSubIndex(char *str, char *substr) {
    for (int i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j]) {
            j++;
        }
        if (substr[j] == '\0') {
            return i;
        }
    }
    return -1;
}
