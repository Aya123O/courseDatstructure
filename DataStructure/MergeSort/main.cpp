#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    int leftArr[sizeLeft], rightArr[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < sizeRight; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] < rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < sizeLeft) {
        arr[k++] = leftArr[i++];
    }

    while (j < sizeRight) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 5, 8, 9, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    display(arr, size);
    cout<<"******************************************************************"<<endl;
    mergeSort(arr, 0, size - 1);

    cout << "After Sorting: ";
    display(arr, size);
    cout<<"******************************************************************"<<endl;

    return 0;
}
