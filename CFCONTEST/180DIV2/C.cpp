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
      vector<int> arr(n);
      for (int i = 0; i < n; i++){
         cin >> arr[i];
      }
      int cnt = 0;
      for (int i = 0; i < n-2; i++){
         int num = arr[i] + arr[i + 1];
         int idx=lower_bound(arr.begin(), arr.end(), num) - arr.begin();
         if(idx==n){
            continue;
         }else{
            int right = n - idx + 1;
            cnt+= right;
         }
      }
   }
}