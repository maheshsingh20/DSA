#include <bits/stdc++.h>
using namespace std;

// Selection Sort

void selectionSort(vector<int> &arr){
  int n = arr.size();
  for(int i = 0; i < n-1; i++){
    int minIndex = i;
    for(int j = i+1; j < n; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
};

void printArray(vector<int>&nums){
  for(int i:nums){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> arr = {4, 2, 7, 5, 6, 1, 8};
  selectionSort(arr);
  printArray(arr);
  return 0;
}
