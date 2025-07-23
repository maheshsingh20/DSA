#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n;i++){
      mp[a[i]].push_back(i);
    }
    int ans = 0;
    for(auto &it:mp){
      int start = -1;
      int first =-1;
      int second = -1;
      vector<int> &v = it.second;
      for (int i = 0; i < v.size();i++){
        int curr=v[i]-start;
        curr -= 1;
        if(curr>first){
          second = first;
          first = curr;
        }else if(curr>second){
          second = curr;
        }else{
          continue;
        }
        start = v[i];

      }
      if(v.back()!=n-1){
        int curr = (n-1)-v.back();
        curr -= 1;
        if(curr>first){
          second = first;
          first = curr;
        }else if(curr>second){
          second = curr;
        }else{
          continue;
        }
      }
      int mid =first/2;
      int currmax = max(mid, second);
      ans = max(ans, currmax);
    }
    cout << ans << endl;
  }
  return 0;
}
