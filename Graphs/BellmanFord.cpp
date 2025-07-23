#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(3));
  for (int i = 0; i < m;i++){
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  vector<int> dist(n, INT_MAX);
  for (int i = 0; i < n - 1;i++){
    for(auot edge:edges){
      int u = edge[0], v = edge[1], w = edge[2];
      if(dis)
    }
  }
}
