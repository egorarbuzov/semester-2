#include <iostream>
#include <cfloat>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main() {
    int twoparm = ivarparm(1, 5);;
    int threeparm = ivarparm(2, 3, 4);
    int fourparm = ivarparm(3, 2, 3, 4);
    int sevenparm = ivarparm(7, 1, 2, 3, 4, 5, 6, 7);

    int twoparm_sv = svarparm(1, 10);
    int threeparm_sv = svarparm(2, 5, 8);
    int fourparm_sv = svarparm(3, 7, 2, 9);
    int sevenparm_sv = svarparm(7, 3, 5, 1, 8, 2, 9, 4);

    int twoparm_fl = fvarparm(1.1f, FLT_MAX);
    int threeparm_fl = fvarparm(2.2f, 3.3f, FLT_MAX);
    int fourparm_fl = fvarparm(1.0f, 2.0f, 3.0f, FLT_MAX);
    int sevenparn_fl = fvarparm(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, FLT_MAX);

    int twoparm_db = dvarparm(1.1, DBL_MAX);
    int threeparm_db = dvarparm(2.2, 3.3, DBL_MAX);
    int fourparm_db = dvarparm(1.0, 2.0, 3.0, DBL_MAX);
    int sevenparm_db = dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, DBL_MAX);

    return 0;
}