#include <iostream>
#include <string>
#include <chrono>

using namespace std;

struct Node {
    int phone;
    string name;
    Node* next;
};

Node* createNode(int phone, string name) {
    Node* newNode = new Node;
    newNode->phone = phone;
    newNode->name = name;
    newNode->next = nullptr;
    return newNode;
}

int hashFunction(int key, int size) {
    return key % size;
}

void insert(Node** table, int size, int phone, string name) {
    int index = hashFunction(phone, size);
    Node* newNode = createNode(phone, name);
    
    newNode->next = table[index];
    table[index] = newNode;
}

Node* search(Node** table, int size, int phone) {
    int index = hashFunction(phone, size);
    Node* current = table[index];
    
    while (current != nullptr) {
        if (current->phone == phone) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void remove(Node** table, int size, int phone) {
    int index = hashFunction(phone, size);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr && current->phone != phone) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) return;

    if (prev == nullptr) {
        table[index] = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
}

void display(Node** table, int size) {
    cout << "\n--- Содержимое хеш-таблицы (размер " << size << ") ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]: ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << "{" << current->phone << ", " << current->name << "} -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

void clearTable(Node** table, int size) {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}

void testPerformance(int size) {
    Node** table = new Node*[size]();
    
    for (int i = 1; i <= 200; i++) {
        insert(table, size, i * 100, "User_" + to_string(i));
    }

    auto start = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 1000; i++) {
        search(table, size, 15000);
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;

    // display(table, size); // для демонстрации вывода
    cout << "Размер таблицы: " << size << " | Время 1000 поисков: " << duration.count() << " мкс" << endl;
    
    clearTable(table, size);
    delete[] table;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int tableSize = 16;
    Node** myTable = new Node*[tableSize]();
    
    
    insert(myTable, tableSize, 12345, "Иванов И.И.");
    insert(myTable, tableSize, 32767, "Петров П.П."); // Максимальное значение
    insert(myTable, tableSize, 123, "Сидоров С.С.");
    
    display(myTable, tableSize);

    cout << "\nПоиск 12345: " << (search(myTable, tableSize, 12345) ? "Найдено" : "Нет") << endl;
    
    remove(myTable, tableSize, 12345);
    cout << "После удаления 12345:";
    display(myTable, tableSize);

    cout << "\n--- Исследование времени поиска ---" << endl;
    testPerformance(16);
    testPerformance(32);
    testPerformance(64);
    testPerformance(128);

    clearTable(myTable, tableSize);
    delete[] myTable;
    return 0;
}
