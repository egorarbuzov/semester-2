#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;
    
    srand(time(0));
    
    vector<int> prices(N);
    
    for (int i = 0; i < N; i++) {
        prices[i] = rand() % 100 + 1;
    }
    
    cout << "Сгенерированные цены: ";
    for (int i = 0; i < N; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;
    
    sort(prices.begin(), prices.end(), greater<int>());
    
    int paidCount = (N + 1) / 2;
    int freeCount = N / 2;
    
    vector<int> order(N);
    
    for (int i = 0; i < paidCount; i++) {
        order[i * 2] = prices[i];
    }
    
    for (int i = 0; i < freeCount; i++) {
        order[i * 2 + 1] = prices[paidCount + i];
    }
    
    long long total = 0;
    for (int i = 0; i < N; i += 2) {
        total += order[i];
    }

    cout << "Порядок пробивания: ";
    for (int i = 0; i < N; i++) {
        cout << order[i] << " ";
    }
    cout << endl;
    
    cout << "Максимальная сумма чека: " << total << endl;
    
    return 0;
}
