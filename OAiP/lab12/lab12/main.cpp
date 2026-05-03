#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int key;
    int a, b, c;
    Node* left;
    Node* right;
};

Node* createNode(int key, int a, int b, int c) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->a = a;
    newNode->b = b;
    newNode->c = c;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key, int a, int b, int c) {
    if (root == NULL) {
        return createNode(key, a, b, c);
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key, a, b, c);
    } else if (key > root->key) {
        root->right = insert(root->right, key, a, b, c);
    }
    
    return root;
}

void findMinSumNode(Node* root, Node** minNode, int* minSum) {
    if (root == NULL) {
        return;
    }
    
    int currentSum = root->a + root->b + root->c;
    
    if (currentSum < *minSum) {
        *minSum = currentSum;
        *minNode = root;
    }
    
    findMinSumNode(root->left, minNode, minSum);
    findMinSumNode(root->right, minNode, minSum);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->a = temp->a;
        root->b = temp->b;
        root->c = temp->c;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node* deleteMinSumNode(Node* root) {
    if (root == NULL) {
        cout << "Дерево пусто!" << endl;
        return NULL;
    }
    
    Node* minNode = NULL;
    int minSum = INT_MAX;
    
    findMinSumNode(root, &minNode, &minSum);
    
    if (minNode != NULL) {
        cout << "Удаляем вершину с ключом " << minNode->key << ", сумма : " << minSum << endl;
        root = deleteNode(root, minNode->key);
    }
    
    return root;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    printTree(root->left);
    cout << "Ключ: " << root->key << ", значения: " << root->a << " " << root->b << " " << root->c<< ", сумма=" << (root->a + root->b + root->c) << endl;
    printTree(root->right);
}

// Очистка памяти
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Ввод данных с консоли
void inputNodeData(int* key, int* a, int* b, int* c) {
    cout << "Введите ключ (целое число): ";
    cin >> *key;
    cout << "Введите три целых числа: ";
    cin >> *a >> *b >> *c;
}

int countRightLeaves(Node* node, bool isRightChild) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        if (isRightChild) {
            return 1;
        } else {
            return 0;
        }
    }
    return countRightLeaves(node->left, false) +
           countRightLeaves(node->right, true);
}

int main() {
    Node* root = NULL;
    int choice, key, a, b, c;
    
    do {
        cout << "1. Добавить вершину" << endl;
        cout << "2. Вывести дерево (симметричный обход)" << endl;
        cout << "3. Удалить вершину с минимальной суммой" << endl;
        cout << "4. Удалить вершину по ключу" << endl;
        cout << "5. Посчитать количество правых листьев" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                inputNodeData(&key, &a, &b, &c);
                root = insert(root, key, a, b, c);
                cout << "Вершина добавлена" << endl;
                break;
                
            case 2:
                if (root == NULL) {
                    cout << "Дерево пусто!" << endl;
                } else {
                    cout << "\nСодержимое дерева:" << endl;
                    printTree(root);
                }
                break;
                
            case 3:
                root = deleteMinSumNode(root);
                break;
                
            case 4:
                if (root == NULL) {
                    cout << "Дерево пусто" << endl;
                } else {
                    cout << "Введите ключ для удаления: ";
                    cin >> key;
                    root = deleteNode(root, key);
                    cout << "Вершина удалена" << endl;
                }
                break;
            
            case 5:
                if (root == NULL) {
                    cout << "Дерево пусто" << endl;
                } else {
                    int result = countRightLeaves(root, false);
                    cout << "Количество правых листьев: " << result << endl;
                }
                break;
                
            case 0:
                break;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
    
    deleteTree(root);
    return 0;
}
