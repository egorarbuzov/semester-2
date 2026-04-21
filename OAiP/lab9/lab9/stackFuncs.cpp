#include "funcs.h"

using namespace std;

void initStack(myStack* stack) {
    stack->topNode = nullptr;
    stack->size = 0;
}

void pushStack(myStack* stack, int value) {
    stackNode* newNode = new stackNode;
    newNode->data = value;
    newNode->next = stack->topNode;
    stack->topNode = newNode;
    stack->size++;
}

int popStack(myStack* stack) {
    if (stack == nullptr || stack->topNode == nullptr) {
        cerr << "Ошибка: стек пуст" << endl;
        return -1;
    }
    
    stackNode* temp = stack->topNode;
    int value = temp->data;
    
    stack->topNode = stack->topNode->next;
    delete temp;
    stack->size--;
    
    return value;
}

void printStack(myStack* stack) {
    cout << "Стек: " << endl;
    stackNode* current = stack->topNode;
    while (current != nullptr) {
        std::cout << current->data << endl;
        current = current->next;
    }
}

void clear(myStack* stack) {
    if (stack == nullptr) return;

    stackNode* current = stack->topNode;
    while (current != nullptr) {
        stackNode* temp = current;
        current = current->next;
        delete temp;
    }
    
    stack->topNode = nullptr;
    stack->size = 0;
}

void parsePosNeg(myStack* stack, myStack* positivestack, myStack* negativestack) {
    stackNode* current = stack->topNode;
    while (current != nullptr) {
        if (current->data > 0) {
            pushStack(positivestack, current->data);
        } else if (current->data < 0) {
            pushStack(negativestack, current->data);
        } else {
            std::cout << "ошибка" << endl;
            break;
        }
        current = current->next;
    }
}

void removeThrElements(myStack* stack) {
    if (stack == nullptr || stack->topNode == nullptr) {
        return;
    }
    
    stackNode* current = stack->topNode;
    stackNode* prev = nullptr;
    
    while (current != nullptr) {
        if (current->data % 3 == 0) {
            if (prev == nullptr) {
                stack->topNode = current->next;
                delete current;
                current = stack->topNode;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            stack->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void loadToFile(myStack* stack, const string& fname) {
    ofstream outFile(fname);
    
    if (!outFile.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return;
    }
    stackNode* current = stack->topNode;
    while (current != nullptr) {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
    cout << "Сохранено в файл" << endl;
}

void loadFromFile(myStack* stack, const string& fname) {
    ifstream inFile(fname);
    
    if (!inFile.is_open()) {
        cerr << "Не удалось открыть файл" << endl;
        return;
    }
    int value;
    while (inFile >> value) {
        pushStack(stack, value);
    }
    
    inFile.close();
    cout << "Стек загружен из файла: " << fname << endl;
}
