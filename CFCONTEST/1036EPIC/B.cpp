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
      for (int i = 0; i < n;i++){
         cin >> arr[i];
      }
      if(n==2){
         int choice1 = arr[0] + min(arr[0], arr[1]);
         int choice2 =arr[0]+arr[1];
         cout << min(choice1, choice2) << endl;
         continue;
      }
      int minn = arr[0];
      int ans = arr[0];
      for (int i = 1; i < n; i++) {
         if(i==n-1 and min(minn,arr[i])>0){
            break;
         }
         minn = min(minn, arr[i]);
         ans += minn;
      }
      cout << ans << endl;
   }
   return 0;
}