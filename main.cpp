#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//这个是我第一次写的
//template<typename T>
//void insertingSort(T arr[], int n) {
//    for (int i = 1; i < n; ++i) {
//        int tempIndex = i;
//        for (int j = i - 1; j >= 0; j--) {
//            if (arr[tempIndex] < arr[j]) {
//                swap(arr[tempIndex], arr[j]);
//                tempIndex = j;
//            }
//        }
//    }
//}

template<typename T>
void insertingSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}


int main() {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("inserting Sort", insertingSort, arr, n);

    delete[] arr;
    return 0;
}

