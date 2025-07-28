#include <bits/stdc++.h>
using namespace std;

/* Max length of a subarray whose xor is 0 */

int main(){
  int n = 6;
  int arr[n] = {2, 3, 3, 2, 3, 3, 1, 6};
  int start=0;
  unordered_map<int, int> mp;
  int ans = 0;
  mp[0] = -1;
  for (int i = 0; i < n;i++){
    ans ^= arr[i];
    if (mp.find(ans) != mp.end()){
      start = max(start, i - mp[ans]);
    }
    if(mp.find(ans)==mp.end()){
      mp[ans] = i;
    }
  }
  cout << start << endl;
  return 0;
}