#include <iostream>
using namespace std;
void heapify(int a[], int n, int i) {
    int smallest = i; //let's assume current child is smallest
    int left = 2 * i + 1; //left child index
    int right = 2 * i + 2; // right child
    /* comprae with left and right both */
    if (left < n && a[left] < a[smallest]) smallest = left;
    if (right < n && a[right] < a[smallest]) smallest = right;
   /*if smallest is not current index, swap and heapify again*/
    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        heapify(a, n, smallest);
    }
}
void buildMinHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}
/* Converts an array into a Min Heap by calling heapify on all non-leaf nodes in reverse order.*/
int findMin(int a[], int &n) {
    int root = a[0];
    a[0] = a[n - 1];
    n--;
    heapify(a, n, 0);
    return root;
}/* The smallest element :root of Min Heap extract that and reduce size to maintain heap and call heapify */
int main() {
    int n, k;
    cin >> n >> k; // taking input of  n number of element in array and k  is number of minimum element to find
    int a[n]; // array to store elements
    // taking input of elements in array
    for (int i = 0; i < n; i++) cin >> a[i];
    buildMinHeap(a, n); // building heap
    for (int i = 0; i < k; i++) {
        cout << findMin(a, n) << " ";  //each time we call it return min from heap and we get k min 
    }
    cout << endl;
    return 0;
}
