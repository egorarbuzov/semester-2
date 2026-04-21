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
    
    vector<int> scores(N);
    
    cout << "Сгенерированные баллы: ";
    for (int i = 0; i < N; i++) {
        scores[i] = rand() % 100 + 1;
        cout << scores[i] << " ";
    }
    cout << endl;
    
    sort(scores.begin(), scores.end(), greater<int>());
    
    int prizersCount = 0;
    int degree = 0;
    int lastScore = -1;
    
    for (int i = 0; i < N; i++) {
        if (scores[i] != lastScore) {
            degree++;
            lastScore = scores[i];
        }
        
        if (degree <= 3) {
            prizersCount++;
        } else {
            break;
        }
    }
    
    cout << "Количество призеров: " << prizersCount << endl;
    
    return 0;
}
