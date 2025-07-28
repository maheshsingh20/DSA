#include <bits/stdc++.h>
using namespace std;
int main(){
  int node = 5;
  int edge = 9;
  unordered_map<int, vector<int>> mp;
  mp[0] = {1,2,3};
  mp[1] = {3,4};
  mp[2] = {3,4};
  mp[3] = {0};
  mp[4] = {3};
  queue <int> qt;
  vector<int> indeg(node, 0);
  for (int i = 0; i < node;i++)
  {
    vector<int> nums = mp[i];
    for(int j:nums){
      indeg[j]++;
    }
  }
  cout << "Indegree Array is: ";
  for (int i = 0; i < node;i++){
    cout << indeg[i] << " ";
  }
  cout << endl;
  qt.push(0);
  vector<int> res;
  while(!qt.empty()){
    int curr = qt.front();
    qt.pop();
    res.push_back(curr);
    for(int i:mp[curr]){
      indeg[i]--;
      if(indeg[i]==0){
        qt.push(i);
      }
    }
  }
  cout << "Tropological order of graph is : ";
  for(int i:res){
    cout << i << " ";
  }
  cout << endl;
  bool isCycle = false;
  for (int i = 0; i < node;i++){
    if(indeg[i]!=0){
      isCycle=true;
      break;
    }
  }
  if( isCycle){
    cout << "Cycle Detected" << endl;
  }else{
    cout << "Cycle not found" << endl;
  }
  return 0;
}