#include <iostream>
#include <cstring>

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_LENGHT = 300;
char books[MAX_BOOKS][MAX_LENGHT];

int main() {
    setlocale(LC_ALL, "Ru");
    
    static int totalBooks = 0;
    bool exit = false;
    
    do {
        cout << "Учет книг:" << endl;
        cout << "Добавить книгу - 1" << endl;
        cout << "Удалить книгу - 2" << endl;
        cout << "Показать все книги - 3" << endl;
        cout << "Выйти - 0" << endl;
        cout << "Выберите действие: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                char bookTitle[MAX_LENGHT];
                cout << "Введите название книги: ";
                cin.ignore();
                cin.getline(bookTitle, MAX_LENGHT);
                
                strcpy(books[totalBooks], bookTitle);
                cout << "Книга " << bookTitle << " добавлена в библиотеку!" << endl;
                totalBooks++;
                break;
            }
            
            case 2: {
                if (totalBooks == 0) {
                    cout << "Библиотека пуста!" << endl;
                    break;
                }
                
                int bookId;
                cout << "Введите номер книги для удаления (1-" << totalBooks << "): ";
                cin >> bookId;
                
                volatile int tempId = bookId - 1;
                
                if (tempId >= 0 && tempId < totalBooks) {
                    cout << "Книга " << books[tempId] << " удалена из библиотеки!" << endl;
                    
                    for (int i = tempId; i < totalBooks - 1; i++) {
                        strcpy(books[i], books[i + 1]);
                    }
                    totalBooks--;
                } else {
                    cout << "Неверный номер книги!" << endl;
                }
                break;
            }
            
            case 3: {
                if (totalBooks == 0) {
                    cout << "Библиотека пуста!" << endl;
                    break;
                }
                
                cout << "Список книг в библиотеке " << endl;
                for (int i = 0; i < totalBooks; i++) {
                    cout << i + 1 << ". " << books[i] << endl;
                }
                break;
            }
            
            case 0: {
                exit = true;
                break;
            }
            
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (!exit);
    
    return 0;
}
