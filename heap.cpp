#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void HeapBottomUp() {
        int n = heap.size() - 1;
        for (int i = n / 2; i >= 1; i--) {
            bool heapFlag = false;
            int v = heap[i];
            while (!heapFlag && 2 * i <= n) {
                int j = 2 * i;
                if (j < n && heap[j] < heap[j + 1]) {
                    j++;
                }
                if (v >= heap[j]) {
                    heapFlag = true;
                } else {
                    heap[i] = heap[j];
                    i = j;
                }
            }
            heap[i] = v;
        }
    }

public:
    MaxHeap(int n) {
        heap.push_back(0);
        cout << "Enter " << n << " elements to build the heap: ";
        for (int i = 1; i <= n; ++i) {
            int value;
            cin >> value;
            heap.push_back(value);
        }
        HeapBottomUp();
    }

    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 1 && heap[index] > heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }

    void deleteRoot() {
        if (heap.size() <= 1) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[1] = heap.back();
        heap.pop_back();
        unsigned int i = 1;
        while (2 * i < heap.size()) {
            unsigned int j = 2 * i;
            if (j + 1 < heap.size() && heap[j] < heap[j + 1]) {
                j++;
            }
            if (heap[i] >= heap[j]) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    void printHeap() {
        if (heap.size() <= 1) {
            cout << "Heap is empty!" << endl;
            return;
        }
        cout << "Heap elements: ";
        for (unsigned int i = 1; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void printRoot() {
        if (heap.size() <= 1) {
            cout << "Heap is empty!" << endl;
            return;
        }
        cout << "Root element: " << heap[1] << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements for the heap: ";
    cin >> n;

    MaxHeap maxHeap(n);

    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete root\n";
        cout << "3. Print heap\n";
        cout << "4. Print root\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                maxHeap.insert(value);
                break;

            case 2:
                maxHeap.deleteRoot();
                break;

            case 3:
                maxHeap.printHeap();
                break;

            case 4:
                maxHeap.printRoot();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                exit(0);
        }
    } while (choice != 5);

    return 0;
}
