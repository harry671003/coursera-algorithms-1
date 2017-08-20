template <typename T>
class MergeSort {
public:
    static void Merge(T *array, T *aux, int low, int high, int mid);

    static bool IsSorted(T *array, int size);
};