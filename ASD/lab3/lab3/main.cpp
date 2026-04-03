#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    srand((unsigned int)time(NULL));
    int SIZE = 0;
    cin >> SIZE;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    
    auto start_bubble = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto end_bubble = std::chrono::high_resolution_clock::now();
    auto bubble_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_bubble - start_bubble);
    
    cout << endl;
    
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << "Время пузырьковой сортировки: " << bubble_duration.count() << " микросекунд" << endl;
    cout << endl << endl;
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    
    auto start_insert = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--){
            swap(arr[j], arr[j - 1]);
        }
    }
    auto end_insert = std::chrono::high_resolution_clock::now();
    auto duration_insert = std::chrono::duration_cast<std::chrono::microseconds>(end_insert - start_insert);
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << "Время сортировкой вставками: " << duration_insert.count() << " микросекунд" << endl;
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    auto start_select = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
    auto end_select = std::chrono::high_resolution_clock::now();
    auto duration_select = std::chrono::duration_cast<std::chrono::microseconds>(end_select - start_select);
    
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    auto start_quick = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, SIZE - 1);
    auto end_quick = std::chrono::high_resolution_clock::now();
    auto duration_quick = std::chrono::duration_cast<std::chrono::microseconds>(end_quick - start_quick);
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    
    cout << endl << endl;
    cout << "Время пузырьковой сортировки: " << bubble_duration.count() << " микросекунд" << endl;
    cout << "Время сортировкой вставками: " << duration_insert.count() << " микросекунд" << endl;
    cout << "Время сортировкой выбора: " << duration_select.count() << " микросекунд" << endl;
    cout << "Время быстрой сортировки: " << duration_quick.count() << " микросекунд" << endl;
    return 0;
}
