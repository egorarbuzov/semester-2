#include "Varparm.h"
#include <cfloat>

namespace Varparm {

    int ivarparm(int amount, ...) {
        int* ptr = &amount + 1;
        int result = 1;
        for (int i = 0; i < amount; i++) {
            result *= ptr[i];
        }
        return result;
    }

    int svarparm(short amount, ...) {
        int* ptr = (int*)(&amount + 1);
        int maxVal = ptr[0];
        for (int i = 1; i < amount; i++) {
            if (ptr[i] > maxVal) {
                maxVal = ptr[i];
            }
        }
        return maxVal;
    }

    double fvarparm(float first, ...) {
        double* ptr = (double*)(&first);
        double sum = 0.0;
        for (int i = 0; ptr[i] != FLT_MAX; i++) {
            sum += ptr[i];
        }
        return sum;
    }

    double dvarparm(double first, ...) {
        double* ptr = &first;
        double sum = 0.0;
        for (int i = 0; ptr[i] != DBL_MAX; i++) {
            sum += ptr[i];
        }
        return sum;
    }

}