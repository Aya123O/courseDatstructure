#include <iostream>
using namespace std;

class SortAlgorithms {
public:
    void BubbleSort(int* arr, int size) {
        int sortted = 0;
        for (int outer = 0; sortted == 0; outer++) {
            for (int inner = 0; inner < size - 1 - outer; inner++) {
                sortted = 1;
                if (arr[inner] > arr[inner + 1]) {
                    int swap = arr[inner];
                    arr[inner] = arr[inner + 1];
                    arr[inner + 1] = swap;
                    sortted = 0;
                }
            }
        }
    }

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

    void SelectionSort(int* arr, int size) {
        int minIndex;
        for (int outer = 0; outer < size - 1; outer++) {
            minIndex = outer;
            for (int inner = outer + 1; inner < size; inner++) {
                if (arr[minIndex] > arr[inner]) {
                    minIndex = inner;
                }
            }
            int swap = arr[outer];
            arr[outer] = arr[minIndex];
            arr[minIndex] = swap;
        }
    }

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

    void quickSort(int* arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

   int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[j] > pivot && j > low) {
            j--;
        }
         if (i < j) {
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }

        while (arr[i] <= pivot && i < high) {
            i++;
        }


    }

    int swap = arr[low];
    arr[low] = arr[j];
    arr[j] = swap;

    return j;
}


    void display(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SortAlgorithms sorter;

    int arr1[5] = {1, 5, 8, 9, 10};
    cout << "Array Before Bubble Sorted \n";
    sorter.display(arr1, 5);
    sorter.BubbleSort(arr1, 5);
    cout << "Array After Bubble Sorted \n";
    sorter.display(arr1, 5);
    cout << "*************************************************\n";

    int arr2[5] = {5, 2, 11, 9, 10};
    cout << "Before Sorting Insertion Sort: ";
    sorter.display(arr2, 5);
    sorter.insertionSort(arr2, 5);
    cout << "After Sorting Insertion Sort: ";
    sorter.display(arr2, 5);
    cout << "*************************************************\n";

    int arr3[5] = {5, 2, 11, 9, 10};
    cout << "Array Before Selection Sorted \n";
    sorter.display(arr3, 5);
    sorter.SelectionSort(arr3, 5);
    cout << "Array After Selection Sorted \n";
    sorter.display(arr3, 5);
    cout << "*************************************************\n";

    int arr4[5] = {1, 5, 8, 9, 7};
    cout << "Before Sorting Merge Sort: ";
    sorter.display(arr4, 5);
    sorter.mergeSort(arr4, 0, 5 - 1);
    cout << "After Sorting Merge Sort: ";
    sorter.display(arr4, 5);
    cout << "*************************************************\n";

    int arr5[5] = {5, 2, 11, 9, 10};
    cout << "Before Sorting Quick Sort: ";
    sorter.display(arr5, 5);
    sorter.quickSort(arr5, 0, 5 - 1);
    cout << "After Sorting Quick Sort: ";
    sorter.display(arr5, 5);
    cout << "*************************************************\n";

    return 0;
}
