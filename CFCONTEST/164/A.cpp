#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n,m,k;
    cin >> n >> m >> k;
    if(m<=k){
      cout << "NO" << "\n";
    }else{
      cout << "YES" << "\n";
    }
  }
  return 0;
}