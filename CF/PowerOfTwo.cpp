#include <bits/stdc++.h>
using namespace std;

void precompute(unordered_set<long long> &m){
  long long i=2;
  while(i<=1e10){
    m.insert(i);
    i*=2;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> v(n);
  unordered_set<long long> m;
  precompute(m);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  long long ans = 0ll;
  for (int i = 0; i < n-1;i++){
    for (int j = i + 1; j < n;j++){
      long long curr=v[i]+v[j];
      if(m.find(curr)!=m.end()){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
