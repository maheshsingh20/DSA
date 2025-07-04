#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, t;
  cin >> n >> t;
  vector<int> books(n);
  for(int i = 0; i < n; i++){
    cin >> books[i];
  }
  int ans = 0;
  int curr = 0;
  int start = 0;
  for(int i = 0; i < n; i++){
    curr+=books[i];
    if(curr<=t){
      ans = max(ans, i-start+1);
    }
    else{
      while(curr>t){
        curr-=books[start];
        start++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
