#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      int m = n;
      int ans = INT_MAX;
      while(m>0){
         int res=m % 10;
         ans=min(ans, res);
         m /= 10;
      }
      cout << ans << "\n";
   }
   return 0;
}