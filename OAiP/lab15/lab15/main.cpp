#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE_A = 10;

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void heapify(int* arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void selectionSort(int* arr, int n) { // доп. задание
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int A[SIZE_A];
    for (int i = 0; i < SIZE_A; i++) {
        cin >> A[i];
    }
    
    int sizeB = (SIZE_A + 1) / 2;
    int B[sizeB];

    int j = 0;
    for (int i = 0; i < SIZE_A; i += 2) {
        B[j] = A[i];
        j++;
    }

    cout << "Исходный массив A: ";
    printArray(A, SIZE_A);
    
    cout << "Массив B: ";
    printArray(B, sizeB);

        // пузырек
    int B1[sizeB];
    copy(B, B + sizeB, B1);
    bubbleSort(B1, sizeB);
    cout << "\nРезультат пузырьковой сортировки: ";
    printArray(B1, sizeB);

        // пирамидальная
    int B2[sizeB];
    copy(B, B + sizeB, B2);
    heapSort(B2, sizeB);
    cout << "Результат пирамидальной сортировки: ";
    printArray(B2, sizeB);

        // выбором
    int B3[sizeB];
    copy(B, B + sizeB, B3);
    selectionSort(B3, sizeB);
    cout << "Результат сортировки выбором: ";
    printArray(B3, sizeB);

        return 0;
}
