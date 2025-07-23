#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>&arr, int n) {
  if(arr[n]<=arr[n-1]){
    return false;
  }
  bool res = true;

  return res  && is_sorted(arr, n + 1);
}

int main(){
  vector<int>arr={1,2,3,4,5,6,7,8,9};
  cout<<isSorted(arr,1)<<endl;
  return 0;
}
