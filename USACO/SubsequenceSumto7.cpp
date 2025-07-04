#include <bits/std++.h>
using namespace std;



int main(){
  int vector<int> arr = {3, 5, 1, 6, 2, 14, 10};
  int sum = 7;
  int n = arr.size();
  unordered_set<pair<int,int>>st;
  int curr = 0;
  st.insert({0,-1});
  for (int i = 0; i < n;i++){
    curr += arr[i];
    int rem = curr % sum;
    if(st.find())
  }
}
