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
      vector<int> num=arr;
      sort(num.begin(), num.end());
      int ans = 0;
      int j = 0;
      unordered_set<int> st;
      while (j < n) {
         if(arr[j]==num[j]){
            st.insert(j);
            ans++;
         }
         j++;
      }
      if(ans==n){
         cout << "NO\n";
      }else{
         cout << "YES\n";
         cout<<n-ans<<"\n";
         for(int i = 0; i < n; i++){
            if(!st.count(i)){
               cout<<arr[i]<<" ";
            }
         }
         cout << "\n";
      }
   }
   return 0;
}