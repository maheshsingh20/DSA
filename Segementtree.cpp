// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// class SegmentTree {
// private:
//     int n; // Size of the input array
//     vector<int> tree; // Segment tree array

//     // Function to build the segment tree
//     void build(const vector<int>& arr, int node, int start, int end) {
//         if (start == end) {
//             // Leaf node
//             tree[node] = arr[start];
//         } else {
//             int mid = (start + end) / 2;
//             // Recursively build left and right subtrees
//             build(arr, 2 * node, start, mid);
//             build(arr, 2 * node + 1, mid + 1, end);
//             // Merge the results (sum in this case)
//             tree[node] = tree[2 * node] + tree[2 * node + 1];
//         }
//     }

//     // Function to query the segment tree
//     int query(int node, int start, int end, int l, int r) {
//         if (r < start || l > end) {
//             // Range is completely outside
//             return 0;
//         }
//         if (l <= start && end <= r) {
//             // Range is completely inside
//             return tree[node];
//         }
//         // Range is partially inside
//         int mid = (start + end) / 2;
//         int left = query(2 * node, start, mid, l, r);
//         int right = query(2 * node + 1, mid + 1, end, l, r);
//         return left + right;
//     }

//     // Function to update the segment tree
//     void update(int node, int start, int end, int idx, int val) {
//         if (start == end) {
//             // Leaf node
//             tree[node] = val;
//         } else {
//             int mid = (start + end) / 2;
//             if (idx <= mid) {
//                 // Update left subtree
//                 update(2 * node, start, mid, idx, val);
//             } else {
//                 // Update right subtree
//                 update(2 * node + 1, mid + 1, end, idx, val);
//             }
//             // Merge the results
//             tree[node] = tree[2 * node] + tree[2 * node + 1];
//         }
//     }

// public:
//     // Constructor
//     SegmentTree(const vector<int>& arr) {
//         n = arr.size();
//         // Allocate memory for the segment tree
//         tree.resize(4 * n); // Safe size to avoid overflow
//         // Build the segment tree
//         build(arr, 1, 0, n - 1);
//     }

//     // Public function to query a range [l, r]
//     int rangeQuery(int l, int r) {
//         return query(1, 0, n - 1, l, r);
//     }

//     // Public function to update a value at index idx
//     void pointUpdate(int idx, int val) {
//         update(1, 0, n - 1, idx, val);
//     }
// };

// int main() {
//     vector<int> arr = {1, 3, 5, 7, 9, 11};
//     SegmentTree st(arr);

//     // Range query example
//     cout << "Sum from index 1 to 4: " << st.rangeQuery(3, 4) << endl; // Output: 24 (3 + 5 + 7 + 9)

//     // Point update example
//     st.pointUpdate(2, 10); // Update index 2 to 10
//     cout << "Sum from index 1 to 4 after update: " << st.rangeQuery(1, 4) << endl; // Output: 29 (3 + 10 + 7 + 9)

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// class SegmentTree {
// private:
//     vector<int> tree;
//     int n;

//     void buildTree(vector<int> &arr, int idx, int start, int end) {
//         if (start == end) {
//             tree[idx] = arr[start];
//         } else {
//             int mid = start + (end - start) / 2;
//             buildTree(arr, 2 * idx + 1, start, mid);
//             buildTree(arr, 2 * idx + 2, mid + 1, end);
//             tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
//         }
//     }

//     void updateQuery(int idx, int start, int end, int index, int val) {
//         if (start == end) {
//             tree[idx] = val;
//             return;
//         }
//         int mid = start + (end - start) / 2;
//         if (index <= mid) {
//             updateQuery(2 * idx + 1, start, mid, index, val);
//         } else {
//             updateQuery(2 * idx + 2, mid + 1, end, index, val);
//         }
//         tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
//     }

//     int rangeQuery(int idx, int start, int end, int l, int r) {
//         if (r < start || l > end) {
//             return 0;
//         }
//         if (l <= start && end <= r) {
//             return tree[idx];
//         }
//         int mid = start + (end - start) / 2;
//         int left = rangeQuery(2 * idx + 1, start, mid, l, r);
//         int right = rangeQuery(2 * idx + 2, mid + 1, end, l, r);
//         return left + right;
//     }

// public:
//     SegmentTree(const vector<int> &arr) {
//         n = arr.size();
//         int height = (int)ceil(log2(n));
//         int max_size = 2 * (int)pow(2, height) - 1;
//         tree.resize(max_size, 0);
//         buildTree(const_cast<vector<int>&>(arr), 0, 0, n - 1);
//         cout << "Segment Tree Created.\n";
//     }

//     ~SegmentTree() {
//         tree.clear();
//         cout << "Segment Tree Destroyed.\n";
//     }

//     void update(int index, int val, vector<int> &arr) {
//         if (index < 0 || index >= n) return;
//         arr[index] = val;
//         updateQuery(0, 0, n - 1, index, val);
//     }

//     void query(vector<int> &arr, int l, int r) {
//         if (l < 0 || r >= n || l > r) {
//             cout << "Invalid Range\n";
//             return;
//         }
//         int result = rangeQuery(0, 0, n - 1, l, r);
//         cout << "Sum of elements in range " << l << " to " << r << " is " << result << endl;
//     }
// };

// int main() {
//     vector<int> arr = {1, 3, 5, 7, 9, 11};
//     SegmentTree st(arr);
//     st.query(arr, 2, 4);
//     st.update(3, 10, arr);
//     st.query(arr, 2, 4);
//     return 0;
// }







/*  Range Minimum Querry  */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Segementtree{
private:
    vector<int> tree;
    void buildTree(vector<int> &arr, int treeIndex, int lo, int hi)
    {
        if (lo == hi)
        {
            tree[treeIndex] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(arr, 2 * treeIndex + 1, lo, mid);
        buildTree(arr, 2 * treeIndex + 2, mid + 1, hi);
        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }
    int rangeQuery(int treeIndex, int lo, int hi, int l, int r){
        if (l > hi || r < lo)
            return INT_MAX;
        if (l <= lo && r >= hi)
            return tree[treeIndex];
        int mid = lo + (hi - lo) / 2;
        int left = rangeQuery(2 * treeIndex + 1, lo, mid, l, r);
        int right = rangeQuery(2 * treeIndex + 2, mid + 1, hi, l, r);
        return min(left, right);
    }
public:
    Segementtree(vector<int> &arr)
    {
        int n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }
    ~Segementtree()
    {
        tree.clear();
        cout << "Segment Tree Destroyed.\n";
    }
    int range(int low, int high){
        if (low < 0 || high >= tree.size() / 4 || low > high) {
            return INT_MAX;;
        }
        return rangeQuery(0, 0, tree.size() / 4 - 1, low, high);
    }
};



int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    Segementtree st(arr);
    cout << st.range(0,3) << endl;
    return 0;
}