#include <bits/stdc++.h>
using namespace std;
struct dt{
  int a, b;
};
int main() {
  vector <dt> mp;
  for (int i = 0; i < 5;i++){
    int u, v;
    cin >> u >> v;
    mp.push_back({u, v});
  }
  for(auto &[u,v]:mp){
    cout<<u<<" "<<v<<endl;
  }
};