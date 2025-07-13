#include <bits/stdc++.h>
using namespace std;


void printArray(vector<pair<int,int>> &arr){
  for(auto i:arr){
    cout <<"("<< i.first<<" "<<i.second << ")";
  }
  cout << endl;
}
int main(){
  vector<pair<int,int>> vec ={{9,3},{9,5},{6,7},{5,4},{5,6},{3,4},{2,3},{1,2}};
  auto sortFun = [](int a, int b) -> bool
  {
    return a>b;
  };
  auto sortFun2 = [](pair<int, int> a, pair<int, int> b) -> bool
  {
    if(a.first == b.first)
    {
      return a.second < b.second;
    }
    else
    {
      return a.first < b.first;
    }
  };
  sort(vec.begin(), vec.end(), sortFun2);
  printArray(vec);
  return 0;
}
