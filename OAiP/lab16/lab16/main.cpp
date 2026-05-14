#include <iostream>

int firstPosHashFunc(int key, int hashTableSize) {
    return key % hashTableSize;
}

int hashFunc(int key, int i, int hashTableSize) {
    int c1 = 1, c2 = 1;
    return (firstPosHashFunc(key, hashTableSize) + c1*i + c2*i*i) % hashTableSize;
}

int main() {
    
}
