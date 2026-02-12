#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
    FILE *NameA, *NameB, *NameC, *NameD;
    int a, b, c;
    int count = 0;
    
    NameA = fopen("NameA.txt", "r");
    NameB = fopen("NameB.txt", "r");
    NameC = fopen("NameC.txt", "r");
    
    while (fscanf(NameA, "%d", &a) == 1) count++;
    rewind(NameA);
    rewind(NameB);
    rewind(NameC);
    
    NameD = fopen("NameD.txt", "w");
    for (int i = 0; i < count; i++) {
        fscanf(NameA, "%d", &a);
        fscanf(NameB, "%d", &b);
        fscanf(NameC, "%d", &c);
        
        fprintf(NameD, "%d ", a);
        fprintf(NameD, "%d ", b);
        fprintf(NameD, "%d ", c);
    }
    
    fclose(NameA);
    fclose(NameB);
    fclose(NameC);
    fclose(NameD);
    
    return 0;
}
