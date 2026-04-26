#include <iostream>
#include <cstdlib>
#include <cctype>

struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    int size;
};

void initQueue(Queue* queue) {
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->size = 0;
}

bool isEmpty(Queue* queue) {
    return queue->front == nullptr;
}

void enqueue(Queue* queue, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

char dequeue(Queue* queue) {
    Node* temp = queue->front;
    char value = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == nullptr) {
        queue->rear = nullptr;
    }
    
    free(temp);
    queue->size--;
    return value;
}

char peek(Queue* queue) {
    if (isEmpty(queue)) {
        return '\0';
    }
    return queue->front->data;
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }
    
    Node* current = queue->front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int getSize(Queue* queue) {
    return queue->size;
}

void clearQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);
    
    char referenceChar;
    char inputChar;
    
    std::cout << "Введите эталонный символ: ";
    std::cin >> referenceChar;
    
    std::cout << "Вводите символы: " << std::endl;
    
    while (true) {
        std::cin >> inputChar;
        
        if (tolower(inputChar) == tolower(referenceChar)) {
            break;
        }
        
        enqueue(&myQueue, inputChar);
    }
    
    std::cout << "\nОчередь: ";
    printQueue(&myQueue);
    
    if (getSize(&myQueue) >= 2) {
        dequeue(&myQueue);
        dequeue(&myQueue);
    } else if (getSize(&myQueue) == 1) {
        dequeue(&myQueue);
    }
    
    std::cout << "\nПосле удаления двух элементов: ";
    printQueue(&myQueue);
    
    clearQueue(&myQueue);
    
    return 0;
}
