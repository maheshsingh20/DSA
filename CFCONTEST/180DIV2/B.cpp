#include <bits/stdc++.h>
using namespace std;

inline bool isValid(int a, int b){
   return abs(a - b) <= 1;
}


int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      if(n < 2){
         cout << -1<<endl;
         break;
      }
      vector<int> arr(n);
      for (int i = 0; i < n; i++){
         cin >> arr[i];
      }
      int cnt = 0;
      bool found = false;
      for(int i=0; i < n - 1; i++){
         /* Check if already exist */
         if(isValid(arr[i], arr[i + 1])){
            found = true;
            cnt = 0;
            break;
         }
         //modify and check 
         cnt++;
         int minn=min(arr[i], arr[i + 1]);
         int maxx=max(arr[i], arr[i + 1]);
         int to_check = arr[i + 2];
         int to_check2 = arr[i + 1]-1;
         if((to_check >= minn && to_check <= maxx) || (to_check2 >= minn && to_check2 <= maxx)){
            found = true;
            break;
         }
      }
      if(found){
         cout << cnt<<endl;
      } else {
         cout << -1 << endl;
      }
   }
   return 0;
}