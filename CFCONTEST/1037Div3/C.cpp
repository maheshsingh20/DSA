#include <iostream>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   cin >> t;
   while(t--){
      int n, m;
      cin >> n >> m;
      vector<int> arr(n);
      for (int i = 0; i < n;i++){
         cin >> arr[i];
      }
      int start = arr[k];

      sort(arr.begin(), arr.end());
      int idx = 0;
      for (int i = n - 1; i >= 0;i--){
         if(arr[i]==start){
            idx = i;
            break;
         }
      }
      bool res = false;
      int lev = 0;
      for (int i = 0; i < n;i++){
         lev += arr[i];
         int gap = arr[idx + 1] - start;
         if(lev>gap){
            res = true;
            break;
         }else{
            if(lev>)
         }
      }
   }
}