#include <iostream>

using namespace std;

#define DIV_7_AND_9(x) ((x) % 7 == 0 && (x) % 9 == 0)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NO_NUMBER_MSG "Числа кратные и 7 и 9 не найдены!"

int main() {
    int n = 0;
    cout << "Введите n (количество чисел): "; cin >> n;
    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (cin.fail()) {
        cout << "Ошибка ввода!" << endl;
        return 1;
    }
    
    int maxNumber = -1;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (DIV_7_AND_9(arr[i])) {
            if (!found) {
                maxNumber = arr[i];
                found = true;
            } else {
                maxNumber = MAX(maxNumber, arr[i]);
            }
        }
    }
    
    if (found) {
        cout << "Наибольшее число: " << maxNumber << endl;
    } else {
        cout << NO_NUMBER_MSG << endl;
    }
    
    delete[] arr;
    return 0;
}
