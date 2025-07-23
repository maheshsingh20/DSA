#include <bits/stdc++.h>
using namespace std;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
  vector<vector<int>> dp(n,vector<int>(m));
  for (int i = 0; i < n;i++) dp[i][0] = dp[i][0] + grid[i][0];
  for (int j = 0; j < m;j++) dp[0][j] = dp[0][j] + grid[0][j];
  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
    }
  }
  cout<<dp[n-1][m-1]<<endl;
  return 0;
}
