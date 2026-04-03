#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    double data;
    Node* next;
};

void clearList(Node*& head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = NULL;
}

Node* createNode(double value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addElement(Node*& head, double value) {
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

void deleteElement(Node*& head, double value) {
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

void searchElement(Node* head, double value) {
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
    
    while (current != NULL) {
        file << current->data << endl;
        current = current->next;
    }
    
    file.close();
    cout << "Список сохранен в файл " << filename << endl;
}

void loadFromFile(Node*& head, string filename) {
    ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }
    
    clearList(head);
    
    double value;
    int count = 0;
    
    while (file >> value) {
        addElement(head, value);
        count++;
    }
    
    file.close();
    cout << "Список загружен из файла " << filename << ". Загружено элементов: " << count << endl;
}

void averagePositive(Node* head) {
    if (head == NULL) {
        cout << "Список пуст!" << endl;
        return;
    }
    
    double sum = 0;
    int count = 0;
    Node* current = head;
    
    while (current != NULL) {
        if (current->data > 0) {
            sum += current->data;
            count++;
        }
        current = current->next;
    }
    
    if (count > 0) {
        double average = sum / count;
        cout << "Среднее значение положительных элементов: " << average << endl;
    } else {
        cout << "Положительных элементов нет!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    
    Node* head = NULL;
    int choice;
    double value;
    string filename;
    
    do {
        cout << "\nВыберите:" << endl;
        cout << "1 - Добавить элемент" << endl;
        cout << "2 - Удалить элемент" << endl;
        cout << "3 - Найти элемент" << endl;
        cout << "4 - Вывести список" << endl;
        cout << "5 - Записать список в файл" << endl;
        cout << "6 - Считать список из файла" << endl;
        cout << "7 - Найти среднее значение положительных элементов" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите значение (вещественное число): ";
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
                averagePositive(head);
                break;
                
            case 0:
                cout << "Программа завершена. До свидания!" << endl;
                break;
                
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
        
    } while (choice != 0);
    
    clearList(head);
    
    return 0;
}
