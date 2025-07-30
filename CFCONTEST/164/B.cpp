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
    int a[n];
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    int prf = 1;
    for (int i = 0; i < n - 1; i++){
      if(a[i] == a[i + 1]){
        prf++;
      } else {
        break;
      }
    }
    int suf = 1;
    for (int i = n - 1; i > 0; i--){
      if(a[i] == a[i - 1]){
        suf++;
      } else {
        break;
      }
    }
    int step = min(prf, suf);
    int res = (step == n) ? -1 : step;
    cout << res << "\n";
  }
  return 0;
}
