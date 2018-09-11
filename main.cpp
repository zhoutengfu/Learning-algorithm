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

//这个是我第一次写的。
// 缺点：1、多了没用的临时tempIndex。
// 2、多了一倍的赋值运算
template<typename T>
void insertingSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int tempIndex = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[tempIndex] < arr[j]) {
                swap(arr[tempIndex], arr[j]);
                tempIndex = j;
            }
        }
    }
}

//去除多余的临时变量
template<typename T>
void insertingSort1(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

//利用临时变量减少赋值运算
template<typename T>
void insertingSort2(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T temp = arr[i];
        for (int j = i-1; j > 0; j--) {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }else {
                arr[j+1] = temp;
                break;
            }
        }
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
//    SortTestHelper::testSort("selection Sort", selectionSort, arr, n);
//    SortTestHelper::testSort("inserting Sort", insertingSort, arr, n);
//    SortTestHelper::testSort("inserting Sort1", insertingSort1, arr, n);

    delete[] arr;
    return 0;
}

