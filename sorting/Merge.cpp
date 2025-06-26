#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int start, int end) {
    int mid = start + (end - start) / 2;
    vector<int> arr1(nums.begin() + start, nums.begin() + mid + 1);
    vector<int> arr2(nums.begin() + mid + 1, nums.begin() + end + 1);

    int i = 0, j = 0, k = start;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            nums[k++] = arr1[i++];
        } else {
            nums[k++] = arr2[j++];
        }
    }

    while (i < arr1.size()) {
        nums[k++] = arr1[i++];
    }

    while (j < arr2.size()) {
        nums[k++] = arr2[j++];
    }
}

void mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, end);
}

int main() {
    vector<int> arr = {8, 3, 7, 5, 6, 8, 1, 2, 9};
    mergeSort(arr, 0, arr.size() - 1);

    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}
