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
    if(n&1!=0){
      cout << "NO" << endl;
      continue;
    }
    string s="";
    int specialCount = 0;
    while(specialCount<n){
      s += "AAB";
      specialCount += 2;
    }
    cout << "YES" << endl;
    cout << s << endl;
  }
}