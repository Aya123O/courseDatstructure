#include <iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {5, 2, 11, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    display(arr, size);
    cout<<"*************************************************"<<endl;
    insertionSort(arr, size);

    cout << "After Sorting: ";
    display(arr, size);
 cout<<"*************************************************"<<endl;
    return 0;
}
