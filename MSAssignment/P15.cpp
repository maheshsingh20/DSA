#include <iostream>
#include <vector>
using namespace std;
/*
Max Heap implementation for Priority-Based Job Scheduling Insert a new job with
priority Extract highest priority job Display current heap (priority order)
*/
class MaxHeap {
private:
    vector<int> heap; // index 0 will be unused for easier calculations
    // Move the new element up to maintain heap property
    void heapifyUp(int index) {
        while (index > 1) {
            int parent = index / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    // Move the root element down to maintain heap property
    void heapifyDown(int index) {
        int size = heap.size() - 1;
        while (true) {
            int left = index * 2;
            int right = index * 2 + 1;
            int largest = index;
            if (left <= size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right <= size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
public:
    MaxHeap() {
        heap.push_back(-1); // dummy value for 1-based indexing
    }
    // Insert a new job
    void insertJob(int priority) {
        heap.push_back(priority);
        heapifyUp(heap.size() - 1);
    }
    // Extract highest priority job
    int extractMax() {
        if (heap.size() <= 1) {
            cout << "[No jobs available]\n";
            return -1;
        }
        int maxVal = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        if (heap.size() > 1) {
            heapifyDown(1);
        }
        return maxVal;
    }
    // Display heap contents
    void displayJobs() {
        if (heap.size() <= 1) {
            cout << "(No jobs in queue)\n";
            return;
        }
        cout << "Jobs by priority: ";
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
};
// Main driver program
int main() {
    MaxHeap scheduler;
    int choice, priority;
    while (true) {
        cout << "\nJob Scheduler Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Execute Highest Priority Job\n";
        cout << "3. Show Jobs in Heap Order\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter job priority (positive integer): ";
                cin >> priority;
                scheduler.insertJob(priority);
                break;
            case 2:
                priority = scheduler.extractMax();
                if (priority != -1) {
                    cout << "[Executed job with priority: " << priority << "]\n";
                }
                break;
            case 3:
                scheduler.displayJobs();
                break;
            case 4:
                cout << "Exiting scheduler...\n";
                return 0;

            default:
                cout << "[Error] Invalid choice.\n";
        }
    }
}
