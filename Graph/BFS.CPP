/* Simple Bfs  */

#include <bits/stdc++.h>
using namespace std;

//directed
void bfs(unordered_map<int, vector<int>> &mp, int start){
  queue<int> qt;
  qt.push(start);
  while(!qt.empty()){
    int curr = qt.front();
    qt.pop();
    cout << curr << " ";
    for(auto &i:mp[curr]){
      qt.push(i);
    }
  }
}

//cycle detetection using bfs

bool isCycle(unordered_map<int, vector<int>>& mp, int start) {
  unordered_map<int, bool> vis;
  queue<pair<int, int>> qt;

  qt.push({start, -1});
  vis[start] = true;

  while (!qt.empty()) {
      int curr = qt.front().first;
      int parent = qt.front().second;
      qt.pop();

      for (auto &t : mp[curr]) {
          if (!vis[t]) {
              vis[t] = true;
              qt.push({t, curr});
          } else if (t != parent) {
              return true;  // Cycle detected
          }
      }
  }
  return false;  // No cycle found
}

// Cycle detection in Undirected graph using bfs
bool isCycle2(unordered_map<int, vector<int>>&mp, int start){
  unordered_map<int, bool> vis;
  queue<pair<int, int>> qt;
  qt.push({start, -1});
  vis[start] = true;
  
}


int main(){
  unordered_map<int, vector<int>> mp;
  /*
  1->2
  2->3
  3->4
  4->5
  */
  int node,edge;
  cin>>node>>edge;
  for(int i=0;i<edge;i++){
    int u,v;
    cin>>u>>v;
    // creating a directed graph
    /*
    0->1>2->4>
    0->3->5->6->7

    */
    mp[u].push_back(v);
  }
  bool res=isCycle(mp, 0);
  if(res){
    cout << "Cycle Detected ";
  }else{
    cout << "No cycle";
  }
  return 0;
}
