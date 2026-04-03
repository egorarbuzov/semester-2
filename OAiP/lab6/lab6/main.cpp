#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>
#include <fstream>

using namespace std;

const int MAX_LIVERS = 100;

struct cityliver {
    string name = "имя не заполнено";
    string surname = "фамилия не заполнена";
    string scnd_surname = "отчество не заполнено";
    string brth_day = "день не введен";
    string brth_month = "месяц не введен";
    string brth_year = "год не введен";
    string address = "адрес не введен";
    string sex = "пол не выбран";
};

cityliver livers[MAX_LIVERS];
int liverscount = 0;

bool isValidSex(const string& sex) {
    return sex == "М" || sex == "Ж" || sex == "м" || sex == "ж";
}

void inputFunc() {
    
    cityliver newLiver;
    
    cout << "Введите ФИО (через пробел): ";
    cin >> newLiver.name >> newLiver.surname >> newLiver.scnd_surname;
    if (cin.fail()) {
        cout << "Ошибка ввода" << endl;
        return;
    }
    cout << endl;
    
    cout << "Введите дату рождения в формате ДД ММ ГГГГ: ";
    cin >> newLiver.brth_day >> newLiver.brth_month >> newLiver.brth_year;
    cout << endl;
    
    cin.clear();
    cout << "Введите адрес: ";
    cin.ignore();
    getline(cin, newLiver.address);
    if (newLiver.address.empty()) {
        getline(cin, newLiver.address);
    }
    cout << endl;
    
    
    cout << "Введите пол (формат М/Ж): ";
    cin >> newLiver.sex;
    if (!isValidSex(newLiver.sex)) {
        cout << "Неверный формат ввода пола" << endl;
        return;
    }
    
    cout << endl;
    
    livers[liverscount] = newLiver;
    liverscount++;
}

void showAllLivers() {
    cout << "Список горожан: " << endl;
    if (liverscount == 0) {
        cout << "Пусто!" << endl;
        return;
    }
    for (int i = 0; i < liverscount; i++) {
        cout << "Горожанин " << i + 1 <<  endl
        <<": ФИО: " <<
                livers[i].name << " " <<
                livers[i].surname << " " <<
                livers[i].scnd_surname << endl <<
        "дата рождения: " << livers[i].brth_day << " " << livers[i].brth_month << " " << livers[i].brth_year << endl <<
        "адрес: " << livers[i].address << endl <<
        "пол: " << livers[i].sex << endl;
        cout << endl;
    }
}

void deleteLiver(int index) {
    for (int i = index; i < liverscount - 1; i++) {
        livers[i] = livers[i + 1];
    }
    liverscount--;
}

void searchInfo() {
    if (liverscount == 0) {
        cout << "Нет данных для поиска!" << endl;
        return;
    }
    
    string searchQuery;
    cin.clear();
    cin.ignore();
    
    cout << "Введите текст для поиска: ";
    getline(cin, searchQuery);
    
    if (searchQuery.empty()) {
        cout << "Ошибка: поисковый запрос не может быть пустым!" << endl;
        return;
    }
    
    bool found = false;
    cout << "Результаты поиска по запросу: " << searchQuery << endl;
    
    for (int i = 0; i < liverscount; i++) {
        if (livers[i].name.find(searchQuery) != string::npos ||
            livers[i].surname.find(searchQuery) != string::npos ||
            livers[i].scnd_surname.find(searchQuery) != string::npos ||
            livers[i].brth_day.find(searchQuery) != string::npos ||
            livers[i].brth_month.find(searchQuery) != string::npos ||
            livers[i].brth_year.find(searchQuery) != string::npos ||
            livers[i].address.find(searchQuery) != string::npos ||
            livers[i].sex.find(searchQuery) != string::npos) {
            
            cout << "Найден в горожанине с номером" << i + 1 << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Ничего не найдено" << endl;
    }
}

void writeToFile() {
    ofstream outFile("citylivers.txt");
    
    outFile << liverscount << endl;
    
    for (int i = 0; i < liverscount; i++) {
        outFile << livers[i].name << endl;
        outFile << livers[i].surname << endl;
        outFile << livers[i].scnd_surname << endl;
        outFile << livers[i].brth_day << endl;
        outFile << livers[i].brth_month << endl;
        outFile << livers[i].brth_year << endl;
        outFile << livers[i].address << endl;
        outFile << livers[i].sex << endl;
    }
    
    outFile.close();
    cout << "Данные записаны в файл" << endl;
}

void readFromFile() {
    ifstream inFile("citylivers.txt");
    
    int fileRecords;
    inFile >> fileRecords;
    
    for (int i = 0; i < fileRecords; i++) {
        cityliver tempLiver;
        
        inFile >> tempLiver.name;
        inFile >> tempLiver.surname;
        inFile >> tempLiver.scnd_surname;
        inFile >> tempLiver.brth_day;
        inFile >> tempLiver.brth_month;
        inFile >> tempLiver.brth_year;
        inFile >> tempLiver.address;
        inFile >> tempLiver.sex;
        livers[liverscount] = tempLiver;
        liverscount++;
    }
    
    inFile.close();
    cout << "Данные считаны из файла" << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int choice = 0;
    do {
        cout << "Выберите: " << endl;
        cout << "1 - ввести данные" << endl;
        cout << "2 - вывести данные" << endl;
        cout << "3 - удалить переменную" << endl;
        cout << "4 - поиск" << endl;
        cout << "5 - записать в файл" << endl;
        cout << "6 - считать с файла" << endl;
        cin >> choice;
        switch(choice) {
            case 1: inputFunc(); break;
            case 2: showAllLivers(); break;
            case 3: {
                int choice = 0;
                cout << "Выберите номер для удаления: " << endl;
                cin >> choice;
                if (choice > liverscount || choice < 1) {
                    cout << "Выбран несуществующий номер" << endl;
                    continue;
                }
                deleteLiver(choice - 1);
                break;
            }
            case 4: searchInfo(); break;
            case 5: writeToFile(); break;
            case 6: readFromFile(); break;
        }
    } while (choice != 0);
    
    
    return 0;
}
