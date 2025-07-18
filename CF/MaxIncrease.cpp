#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int ans = 1;
  int curr = 1;
  for(int i = 1; i < n; i++){
    if(arr[i] > arr[i-1]){
      curr++;
    }
    else{
      ans=max(ans,curr);
      curr = 1;
    }
  }
  ans = max(ans,curr);
  cout << ans << endl;
  return 0;
}
