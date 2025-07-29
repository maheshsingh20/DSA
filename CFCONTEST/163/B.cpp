#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
      cin >> arr[i];
    }
    bool isTrue = 0;
    int last = arr[n-1];
    for (int i = n - 2; i >= 0;i--){
      if (arr[i] <= last){
        last = arr[i];
        continue;
      }
      if(arr[i]%10>last){
        isTrue = true;
        break;
      }
      if(arr[i]%10<arr[i]/10){
        isTrue = true;
        break;
      }
      last = arr[i]/10;
    }
    if(!isTrue) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}