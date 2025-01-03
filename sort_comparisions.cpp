#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

int main() {
    vector<int> sizes = {10, 100, 500, 1000, 5000, 10000};

    for (int size : sizes) {
        cout << "Array Size: " << size << endl;
        vector<int> arr = generateRandomArray(size);


        vector<int> arr1 = arr;
        auto start = high_resolution_clock::now();
        insertionSort(arr1);
        auto end = high_resolution_clock::now();
        auto insertionDuration = duration_cast<milliseconds>(end - start);
        cout << "Insertion Sort Time: " << insertionDuration.count() << " ms" << endl;

        vector<int> arr2 = arr;
        start = high_resolution_clock::now();
        quickSort(arr2, 0, arr2.size() - 1);
        end = high_resolution_clock::now();
        auto quickSortDuration = duration_cast<milliseconds>(end - start);
        cout << "QuickSort Time: " << quickSortDuration.count() << " ms" << endl;

        cout << endl;
    }

    return 0;
}
