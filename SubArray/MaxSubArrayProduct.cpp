#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> nums = {1, 2, 3, 0, 4, 5, 0, 1, 2};
  int ans = nums[0];
  int maxProd = nums[0];
  int minProd = nums[0];
  for (int i = 1; i < nums.size();i++){
    int temp = maxProd;
    maxProd = max({nums[i], nums[i] * maxProd, minProd * nums[i]});
    minProd = min({nums[i], temp * nums[i], minProd * nums[i]});
    ans = max(ans, maxProd);
  }
  cout << ans;
}