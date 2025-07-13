#include <bits/stdc++.h>
using namespace std;
/*Diagonals*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    if(k<=n){
      cout <<(k>0)<<endl;
      continue;
    }
    k -= n;
    n--;
    int ans = 1;
    while(k>0){
      //first case
      k -= n;
      ans++;
      if(k<=0) break;
      //
      k -= n;
      ans++;
      //update n
      n--;
    }
    cout << ans<<endl;
  }
  return 0;
}
