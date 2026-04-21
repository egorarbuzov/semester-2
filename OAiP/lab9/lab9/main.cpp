#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
    myStack mystack;
    myStack positiveStack;
    myStack negativeStack;
    
    initStack(&mystack);
    initStack(&positiveStack);
    initStack(&negativeStack);
    
    int choice = 0;
    int value;
    string filename;
    
    do {
        cout << "1 - Добавить элемент" << endl;
        cout << "2 - Извлечь элемент" << endl;
        cout << "3 - Вывести стек" << endl;
        cout << "4 - Создать положительный и отрицательный стек" << endl;
        cout << "5 - Удалить элементы, кратные трем" << endl;
        cout << "6 - Записать в файл" << endl;
        cout << "7 - Загрузить из файла" << endl;
        cout << "8 - Очистить стек" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите число для добавления: ";
                cin >> value;
                pushStack(&mystack, value);
                cout << "Элемент " << value << " добавлен в стек" << endl;
                break;
                
            case 2:
                value = popStack(&mystack);
                if (value != -1) {
                    cout << "Извлечен элемент: " << value << endl;
                }
                break;
                
            case 3:
                if (mystack.size == 0) {
                    cout << "Стек пуст" << endl;
                } else {
                    printStack(&mystack);
                }
                break;
                
            case 4:
                clear(&positiveStack);
                clear(&negativeStack);
                initStack(&positiveStack);
                initStack(&negativeStack);
                parsePosNeg(&mystack, &positiveStack, &negativeStack);
                cout << "Разделение выполнено" << endl;
                cout << "Положительные числа: " << endl;
                if (positiveStack.size == 0) {
                    cout << "  (нет положительных чисел)" << endl;
                } else {
                    printStack(&positiveStack);
                }
                cout << "Отрицательные числа: " << endl;
                if (negativeStack.size == 0) {
                    cout << "  (нет отрицательных чисел)" << endl;
                } else {
                    printStack(&negativeStack);
                }
                break;
                
            case 5:
                removeThrElements(&mystack);
                cout << "Элементы, кратные трем, удалены" << endl;
                break;
                
            case 6:
                cout << "Введите имя файла для сохранения: ";
                cin >> filename;
                loadToFile(&mystack, filename);
                break;
                
            case 7:
                cout << "Введите имя файла для загрузки: ";
                cin >> filename;
                loadFromFile(&mystack, filename);
                cout << "Стек загружен" << endl;
                break;
                
            case 8:
                clear(&mystack);
                cout << "Стек очищен" << endl;
                break;
                
            case 0:
                break;
                
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 0);
    
    clear(&mystack);
    clear(&positiveStack);
    clear(&negativeStack);
    
    return 0;
}
