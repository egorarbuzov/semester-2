#include <iostream>
#include <cstdlib>

struct Node {
    char data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    int size;
};

void initQueue(Queue* q) {
    q->front = q->rear = nullptr;
    q->size = 0;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        std::cout << "Ошибка памяти!\n";
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;
    
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

char dequeue(Queue* q) {
    if (isEmpty(q)) {
        return '\0';
    }
    Node* temp = q->front;
    char value = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = nullptr;
    free(temp);
    q->size--;
    return value;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Очередь пуста\n";
        return;
    }
    Node* current = q->front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int getSize(Queue* q) {
    return q->size;
}

int main() {
    Queue queue;
    initQueue(&queue);
    
    char inputChar;
    int totalInput = 0;
    
    std::cout << "Вводите символы (для выхода введите '!'):" << std::endl;
    
    while (true) {
        std::cin >> inputChar;
        
        if (inputChar == '!') {
            break;
        }
        
        totalInput++;
        
        if (totalInput > 5) {
            dequeue(&queue);
        }
        
        enqueue(&queue, inputChar);
    }
    
    std::cout << "\nСодержимое очереди: ";
    printQueue(&queue);
    
    std::cout << "Количество элементов в очереди: " << getSize(&queue) << std::endl;
    
    // Очистка памяти
    while (!isEmpty(&queue)) {
        dequeue(&queue);
    }
    
    return 0;
}
