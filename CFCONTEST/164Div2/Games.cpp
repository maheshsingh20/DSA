#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> pr;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    pr.push_back({a, b});
    mp[b]++;
  }
  int ans = 0;
  for (int i = 0; i < n;i++){
    int a = pr[i].first;
    if(mp[a]>0){
      ans += mp[a];
    }
  }
  cout << ans << endl;
  return 0;
}