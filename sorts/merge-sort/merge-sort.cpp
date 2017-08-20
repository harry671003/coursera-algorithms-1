#include "merge-sort.hpp"

template <typename T>
void MergeSort<T>::Merge(T *array, T *aux, int low, int high, int mid) {
    for(int k = low; k <= high; k++) {
        aux[k] = array[k];
    }

    int i = low;
    int j = mid + 1;

    for(int k = low; k <= high; k++) {
        if(i > mid) array[k] = aux[j++];
        else if(j > high) array[k] = aux[i++];
        else if(aux[i] < aux[j]) array[k] = aux[i++];
        else array[k] = aux[j++];
    }
}

template <typename T>
bool MergeSort<T>::IsSorted(T *array, int size) {
    for(int i = 1; i < size; i++) {
        if(array[i - 1] > array[i]) {
            return false;
        }
    }

    return true;
}