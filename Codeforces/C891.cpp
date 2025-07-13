#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int size = n * (n - 1) / 2;
    vector<int> v(size);
    map<int, int, greater<int>> mp;
    for(int i = 0; i < size; i++){
      cin >> v[i];
      mp[v[i]]++;
    }
    int ans = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
      if(it->second > 0){
        cout << it.first << " ";
        it.second -= x;
        x++;
      }
    }
    cout << endl;
  }
  return 0;
}
