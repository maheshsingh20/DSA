/*
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int node, edge;
  cin >> node >> edge;
  vector<vector<int>> Gp (node,vector<int>(node, 0));
  for(int i = 0; i < edge; i++){
    int u, v;
    cin >> u >> v;
    Gp[u][v] = 1; // Assumi ng directed graph
    // Gp[v][u] = 1; // Uncomment for undirected graph
  }
  for(int i = 0; i < node; i++){
    for(int j = 0; j < node; j++){
      cout << Gp[i][j] << " ";
    }
    cout << endl;
  }
}
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int node, edge;
  cin >> node >> edge;
  unordered_map<int, vector<int>> mp;  
  for(int i = 0; i < edge; i++){
    int u, v;
    cin >> u >> v;
    mp[u].push_back(v); // Assuming directed graph
    // mp[v].push_back(u); // Uncomment for undirected graph
  }
  for(int i = 0; i < node; i++){
    cout << i << " -> ";
    for(auto &j : mp[i]){
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}