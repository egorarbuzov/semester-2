#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fA, *fB, *fC;
    int cols1, cols2, rows1, rows2;
    double **M1, **M2, **M3;
    
    fA = fopen("fA.txt", "r");
    fB = fopen("fB.txt", "r");
    fC = fopen("fC.txt", "w");
    
    fscanf(fA, "%d", &cols1);
    fscanf(fB, "%d", &cols2);
    
    rows1 = 0;
    double temp;
    while (fscanf(fA, "%lf", &temp) == 1) rows1++;
    rows1 = rows1 / cols1;
    
    rows2 = 0;
    rewind(fB);
    fscanf(fB, "%d", &cols2);
    while (fscanf(fB, "%lf", &temp) == 1) rows2++;
    rows2 = rows2 / cols2;
    
    if (cols1 != rows2) {
        fclose(fA);
        fclose(fB);
        fclose(fC);
        fC = fopen("fC.txt", "w");
        fclose(fC);
        return 0;
    }
    
    M1 = (double**)malloc(rows1 * sizeof(double*));
    M2 = (double**)malloc(rows2 * sizeof(double*));
    M3 = (double**)malloc(rows1 * sizeof(double*));
    
    for (int i = 0; i < rows1; i++) {
        M1[i] = (double*)malloc(cols1 * sizeof(double));
        M3[i] = (double*)malloc(cols2 * sizeof(double));
    }
    for (int i = 0; i < rows2; i++) {
        M2[i] = (double*)malloc(cols2 * sizeof(double));
    }
    
    rewind(fA);
    fscanf(fA, "%d", &cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            fscanf(fA, "%lf", &M1[i][j]);
        }
    }
    
    rewind(fB);
    fscanf(fB, "%d", &cols2);
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            fscanf(fB, "%lf", &M2[i][j]);
        }
    }
    

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            M3[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    
    fprintf(fC, "%d\n", cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            fprintf(fC, "%.1f ", M3[i][j]);
        }
        fprintf(fC, "\n");
    }
    
    for (int i = 0; i < rows1; i++) {
        free(M1[i]);
        free(M3[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(M2[i]);
    }
    free(M1);
    free(M2);
    free(M3);
    
    fclose(fA);
    fclose(fB);
    fclose(fC);
    
    return 0;
}
