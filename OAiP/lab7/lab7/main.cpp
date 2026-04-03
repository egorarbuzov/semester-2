#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addElement(Node*& head, int value) {
    Node* newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Элемент " << value << " добавлен" << endl;
}

void deleteElement(Node*& head, int value) {
    if (head == NULL) {
        cout << "Список пуст! Нет элементов для удаления." << endl;
        return;
    }
    
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Элемент " << value << " удален!" << endl;
        return;
    }
    
    Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Элемент " << value << " удален!" << endl;
    } else {
        cout << "Элемент " << value << " не найден!" << endl;
    }
}

void searchElement(Node* head, int value) {
    if (head == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    
    Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == value) {
            cout << "Элемент " << value << " найден на позиции " << position << endl;
            return;
        }
        current = current->next;
        position++;
    }
    
    cout << "Элемент " << value << " не найден!" << endl;
}

void printList(Node* head) {
    if (head == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    
    Node* current = head;
    cout << "Список: ";
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void saveToFile(Node* head, string filename) {
    ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    
    Node* current = head;
    int count = 0;
    
    while (current != NULL) {
        file << current->data << endl;
        current = current->next;
        count++;
    }
    
    file.close();
    cout << "Список сохранен в файл" << endl;
}

void loadFromFile(Node*& head, string filename) {
    ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
    
    int value;
    int count = 0;
    
    while (file >> value) {
        addElement(head, value);
        count++;
    }
    
    file.close();
    cout << "Список загружен из файла" << endl;
}

void sumPositive(Node* head) {
    if (head == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    
    int sum = 0;
    bool found = false;
    Node* current = head;
    
    while (current != NULL) {
        if (current->data > 0) {
            sum += current->data;
            found = true;
        }
        current = current->next;
    }
    
    if (found) {
        cout << "Сумма положительных элементов: " << sum << endl;
    } else {
        cout << "Положительных элементов нет!" << endl;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    
    Node* head = NULL;
    int choice, value;
    string filename;
    
    do {
        cout << "Выберите: " << endl;
        cout << "1 - Добавить элемент" << endl;
        cout << "2 - Удалить элемент" << endl;
        cout << "3 - Найти элемент" << endl;
        cout << "4 - Вывести список" << endl;
        cout << "5 - Записать список в файл" << endl;
        cout << "6 - Считать список из файла" << endl;
        cout << "7 - Найти сумму положительных элементов" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите значение: ";
                cin >> value;
                addElement(head, value);
                break;
                
            case 2:
                if (head == NULL) {
                    cout << "Список пуст! Нечего удалять." << endl;
                } else {
                    cout << "Введите значение для удаления: ";
                    cin >> value;
                    deleteElement(head, value);
                }
                break;
                
            case 3:
                if (head == NULL) {
                    cout << "Список пуст! Нечего искать." << endl;
                } else {
                    cout << "Введите значение для поиска: ";
                    cin >> value;
                    searchElement(head, value);
                }
                break;
                
            case 4:
                printList(head);
                break;
                
            case 5:
                if (head == NULL) {
                    cout << "Список пуст! Нечего сохранять." << endl;
                } else {
                    cout << "Введите имя файла: ";
                    cin >> filename;
                    saveToFile(head, filename);
                }
                break;
                
            case 6:
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(head, filename);
                break;
                
            case 7:
                sumPositive(head);
                break;
                
            case 0: // Выход
                cout << "Программа завершена. До свидания!" << endl;
                break;
                
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
        
    } while (choice != 0);
    
    // Освобождаем память перед выходом
    
    return 0;
}
