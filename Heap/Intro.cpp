#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  vector<int> arr = {8, 5, 3, 4, 2, 7, 5};
  int n = arr.size();
  make_heap(arr.begin(), arr.end());
  arr.push_back(9);
  push_heap(arr.begin(), arr.end());
  for (int i = 0; i < n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
