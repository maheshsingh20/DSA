#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> arr = {1, 2, 3, 0, 4, 5, 0, 1, 2};
  int ans = arr[0];
  int maxProd = arr[0];
  int minProd = arr[0];
  for (int i = 1; i < arr.size();i++){
    int temp = maxProd;
    maxProd = max({arr[i], arr[i] * maxProd, minProd * arr[i]});
    minProd = min({arr[i], temp * arr[i], minProd * arr[i]});
    ans = max(ans, maxProd);
  }
  cout << ans;
}