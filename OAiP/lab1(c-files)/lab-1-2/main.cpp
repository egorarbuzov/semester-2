#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    FILE *f, *g;
    int K, num;
    
    f = fopen("f.txt", "r");
    g = fopen("g.txt", "w");
    
    cout << "Введите K: "; cin >> K;
    
    while (fscanf(f, "%d", &num) == 1) {
        if ((num >= 10 && num <= 99) ||
            (num <= -10 && num >= -99)) {
            if (num % K == 0) {
                fprintf(g, "%d ", num);
            }
        }
    }
}
