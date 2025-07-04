#include <bits/stdc++.h>
using namespace std;

int arr[5];
int dp[100][105];

int recur(int level, int sumleft){
  if(level == 5){
    if(sumleft == 0){
      return 1;
    }
    else{
      return 0;
    }
  }
  if(dp[level][sumleft] != -1){
    return dp[level][sumleft];
  }
  int ans = 0;
  int take=recur(level+1, sumleft-arr[level]);
  int notake = recur(level+1, sumleft);
  if(take == 1 || notake == 1){
    ans = 1;
  }
  return dp[level][sumleft] = ans;
}


void solve(){

  int n;//number of queries
  cin>>n;
  memset(dp, -1,sizeof(dp));
  recur
  while(n--){
    int querry;
    cin >> querry;

  }
}

int main() {
  solve();
  return 0;
}
