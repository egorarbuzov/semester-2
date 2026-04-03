#include <iostream>

using namespace std;

const int MAX_HISTORY = 100;
const int MAX_LENGHT = 200;
char history[MAX_HISTORY][MAX_LENGHT];

int main() {
    setlocale(LC_ALL, "ru");
    
    static float exchangeRate = 2.9;
    static int exchangesCount = 0;
    bool end = false;
    

    do {
        cout << "Конвертация валют: " << endl;
        cout << "Конвертировать USD в BYN - 1" << endl;
        cout << "История конвертаций - 2" << endl;
        cout << "Выход - 0" << endl;
        cout << "Выберите: ";
        int choice; cin >> choice;
        switch (choice) {
            case 1: {
                double usd;
                cout << "Введите сумму USD: "; cin >> usd;
                
                volatile double byn = usd * exchangeRate;
                char historyadd[MAX_LENGHT];
                sprintf(historyadd, "Конвертация usd %.2f в byn %.2f", usd, byn);
                if (exchangesCount < MAX_HISTORY) {
                    strcpy(history[exchangesCount], historyadd);
                    exchangesCount++;
                    cout << "Запись в истории создана!" << endl;
                }
                break;
                
            }
            case 2: {
                if (exchangesCount == 0) {
                    cout << "История пуста" << endl;
                    break;
                }
                cout << "История обменов: " << endl;
                for (int i = 0; i < exchangesCount; i++) {
                    cout << i + 1 << ". " << history[i] << endl;
                }
                break;
            }
            case 0: {
                end = true;
                break;
            }
        }
        
        } while (end == false);
        
        return 0;
    }
