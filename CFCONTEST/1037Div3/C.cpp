#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin >> t;
   while(t--){
      int n, k;
      cin >> n >> k;
      vector<int> arr(n);
      for (int i = 0; i < n; i++){
         cin >> arr[i];
      }
      int curr = k-1;
      int currElement = arr[curr];
      sort(arr.begin(), arr.end());
      for (int i = n-1; i >= 0;i--){
         if(arr[i]==currElement){
            curr = i;
            break;
         }
      }
      int start = 0;
      int currIndex = curr;
      bool res = true;
      while(currIndex < n){
         int need=arr[currIndex+1]-arr[currIndex];
         int available = arr[currIndex] - start;
         if(available>=need){
            start += need;
            currIndex++;
         }else{
            res = false;
            break;
         }
      }
      if(res){
         cout<<"YES\n";
      }else{
         cout << "NO\n";
      }
   }
   return 0;
}