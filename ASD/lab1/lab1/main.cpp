#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long fibCycle(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

int main() {
    int n;
    cout << "Введите N: ";
    cin >> n;
    
    auto start1 = high_resolution_clock::now();
    long long result1 = fibCycle(n);
    auto end1 = high_resolution_clock::now();
    
    auto start2 = high_resolution_clock::now();
    long long result2 = fibRec(n);
    auto end2 = high_resolution_clock::now();
     
    cout << "Число Фибоначчи: " << result1 << endl;
    
    if (result1 != result2) {
        cout << "Ошибка: результаты не совпадают!" << endl;
        cout << "Линейный: " << result1 << ", Рекурсивный: " << result2 << endl;
    }
    
    auto time1 = duration_cast<milliseconds>(end1 - start1).count();
    auto time2 = duration_cast<milliseconds>(end2 - start2).count();
    
    long long min1 = time1 / 60000;
    long long sec1 = (time1 % 60000) / 1000;
    long long ms1 = time1 % 1000;
    
    long long min2 = time2 / 60000;
    long long sec2 = (time2 % 60000) / 1000;
    long long ms2 = time2 % 1000;
    
    cout << "Время линейного способа: " << min1 << " мин " << sec1 << "." << ms1 << " сек" << endl;
    cout << "Время рекурсивного способа: " << min2 << " мин " << sec2 << "." << ms2 << " сек" << endl;
    
    return 0;
}
