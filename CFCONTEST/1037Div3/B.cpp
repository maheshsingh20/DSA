#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while(t--){
      int n, m;
      cin >> n >> m;
      vector<int> arr(n);
      for (int i = 0;i<n;i++){
         cin >> arr[i];
      }
      int ans = 0;
      int curr = 0;
      int i = 0;
      while(i<n){
         while (i < n and curr <m and arr[i]==0){
            curr++;
            i++;
         }
         if(curr==m){
            ans++;
            curr = 0;
            i++;
         }else{
            curr = 0;
            i++;
         }
      }
      cout<<ans<<"\n";
   }
   return 0;
}