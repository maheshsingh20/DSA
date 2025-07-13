#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> b(m);
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  int ans = INT_MIN;
  for (int i = 0; i < n;i++){
    int d = 1e9;
    int l= lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
    if(l>=0){
      d = min(d, abs(a[i] - b[l]));
    }
    if(l+1<=m){
      d = min(d, abs(a[i]- b[i + 1]));
    }
    ans = max(ans, d);
  }
  cout<<ans<<endl;
  return 0;
}
