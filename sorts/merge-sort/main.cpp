#include <iostream>
#include "merge-sort.cpp"

using namespace std;

int main() {
    int size = 9;
    int arr[] = { 2, 3, 5, 9, 1, 4, 6, 7, 8 };
    int aux[9];

    MergeSort<int>::Merge(arr, aux, 0, size - 1, 3);

    cout << "Sorted: " << MergeSort<int>::IsSorted(arr, size) << endl;

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}