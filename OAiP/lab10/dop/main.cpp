#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> fishes;
    int n, fish;
    
    cout << "Сколько рыб? ";
    cin >> n;
    
    cout << "Введите размеры рыб по парам (+ если плывет вправо, - если влево): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> fish;
        fishes.push_back(fish);
    }
    
    cout << "\nНачальные пары рыб: ";
    for (int i = 0; i < fishes.size(); i++) {
        cout << fishes[i] << " ";
    }
    cout << endl;
    
    deque<int> result;
    
    for (int current : fishes) {
        bool alive = true;
        
        while (!result.empty() && current < 0 && result.back() > 0) {
            int last = result.back();
            
            if (abs(last) > abs(current)) {
                alive = false;
                break;
            }
            else if (abs(last) < abs(current)) {
                result.pop_back();
            }
            else {
                result.pop_back();
                alive = false;
                break;
            }
        }
        
        if (alive) {
            result.push_back(current);
        }
    }
    
    cout << "\nОставшиеся рыбы: ";
    if (result.empty()) {
        cout << "все погибли ";
    } else {
        for (int f : result) cout << f << " ";
    }
    cout << endl;
    
    return 0;
}
