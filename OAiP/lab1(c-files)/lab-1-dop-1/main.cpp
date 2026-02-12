#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
    FILE *start, *result;
    int cols, rows;
    double **A, **B;
    double temp;
    
    start = fopen("start.txt", "r");
    fscanf(start, "%d", &cols);
    rows = 0;
    
    while(fscanf(start, "%lf", &temp) == 1) rows++;
    rows = rows / cols;
    
    A = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        A[i] = (double*)malloc(cols * sizeof(double));
    }
    
    rewind(start);
    fscanf(start, "%d", &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(start, "%lf", &A[i][j]);
        }
    }
    fclose(start);
    
    B = (double**)malloc(cols * sizeof(double*));
    for (int i = 0; i < cols; i++) {
        B[i] = (double*)malloc(rows * sizeof(double));
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[j][i] = A[i][j];
        }
    }
    
    result = fopen("result.txt", "w");
    fprintf(result, "%d\n", rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            fprintf(result, "%.2f ", B[i][j]);
        }
        fprintf(result, "\n");
    }
    fclose(result);
    for (int i = 0; i < rows; i++) free(A[i]);
    free(A);
    
    for (int i = 0; i < cols; i++) free(B[i]);
    free(B);
    
    return 0;

}
