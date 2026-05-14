#include <iostream>
#include <string>

using namespace std;

struct Node {
    int number;
    string name;
    Node* next;
};

int hashFunc(int number, int size) {
    return (number % 174 + 932 - 232) % size;
}



int main() {
    cout << hashFunc(95, 16);
    return 0;
}
