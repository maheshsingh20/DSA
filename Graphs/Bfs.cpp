#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  unordered_map<int,vector<int>> mp;
  int node, edge;
  cin >> node >> edge;
  for (int i = 0; i < edge;i++){
    int u, v;
    cin >> u >> v;
    mp[u].push_back(v);  //directed graph
  }
  //
  queue<int> qt;
  
}