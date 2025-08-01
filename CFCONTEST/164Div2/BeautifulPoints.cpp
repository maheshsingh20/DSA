#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int j = min(n, m);
  cout << j+1 << endl;
  for (int i = 0;i<=j;i++){
    cout << i << " " << j << endl;
  }
  return 0;
}