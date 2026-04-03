#include <iostream>
#include <string>
#include <cctype> // для isdigit

using namespace std;

struct train {
    string place;
    int numbTrain;
    string time;
};

bool isValidTime(const string& time) {
    if (time.length() != 5) {
        return false;
    }
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            if (time[i] != ':') {
                return false;
            }
        } else {
            if (!isdigit(time[i])) {
                return false;
            }
        }
    }
    
    int hours = stoi(time.substr(0, 2));
    if (hours < 0 || hours > 23) {
        return false;
    }
    
    int minutes = stoi(time.substr(3, 2));
    if (minutes < 0 || minutes > 59) {
        return false;
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int const SIZE = 3;
    train trains[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        cout << "\nПоезд #" << (i + 1) << ":\n";

        cout << "Введите место отправления: ";
        getline(cin, trains[i].place);
        
        cout << "Номер поезда: ";
        cin >> trains[i].numbTrain;
        
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите число: ";
            cin >> trains[i].numbTrain;
        }
        
        cin.ignore(10000, '\n');
        bool validTime = false;
        while (!validTime) {
            cout << "Время отправления (ЧЧ:ММ): ";
            getline(cin, trains[i].time);
            
            if (isValidTime(trains[i].time)) {
                validTime = true;
            } else {
                cout << "Ошибка, неверный формат времени!" << endl;
            }
        }
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (trains[j].place > trains[j + 1].place) {
                train temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }
    
    cout << "\nОтсортированный список поездов:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ". " << trains[i].place
            << " - №" << trains[i].numbTrain
            << ", отправление: " << trains[i].time << endl;
    }

    cout << "\nВведите время для поиска (ЧЧ:ММ): ";
    string searchTime;
    getline(cin, searchTime);
    
    while (!isValidTime(searchTime)) {
        cout << "Неверный формат! Введите время (ЧЧ:ММ): ";
        getline(cin, searchTime);
    }

    cout << "\nПоезда, отправляющиеся после " << searchTime << ":\n";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (trains[i].time > searchTime) {
            cout << "Пункт назначения: " << trains[i].place << endl;
            cout << "Номер поезда: " << trains[i].numbTrain << endl;
            cout << "Время отправления: " << trains[i].time << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Нет поездов, отправляющихся после указанного времени.\n";
    }
}
