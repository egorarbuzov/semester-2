#include <iostream>

using namespace std;

int main() {
    int N = 0;
    cout << "Введите число N: "; cin >> N;
    bool found = false;
    int left_border = 1;
    int right_border = N;
    int iteration_amount = 0;
    while (found == false) {
        cout << "Ваше число " << X << " ?" << endl;
        int choice = 0;
        cout << "Выберите: мало - 1, много - 2, угадал - 3" << endl; cin >> choice;
        switch (choice) {
            case 1:
                X = X + X / 2;
                break;
            case 2:
                X = X - X / 2;
                break;
            case 3:
                cout << "Ваше число: " << X << " !";
                found = true;
                break;
        }
        iteration_amount++;
     }
    
    cout << "Количество итераций: " << iteration_amount << endl;
    return 0;
}
