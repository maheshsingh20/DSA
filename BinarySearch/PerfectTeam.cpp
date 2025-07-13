#include <bits/stdc++.h>
using namespace std;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int querries;
  cin >> querries;
  while(querries--){
    int c, m, x;
    cin >> c >> m >> x;
    int n = c + m + x;
    int end = n / 3 + 1;
    int start = 1;
    while(start+1<end){
      int mid = start + (end - start) / 2;
      if(mid<=c && mid<=m && 3*mid<=n){
        start = mid;
      }else{
        end = mid;
      }
    }
    cout << start << endl;
  }
}
