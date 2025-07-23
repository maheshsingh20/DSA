#include <bits/stdc++.h>
using namespace std;
int main(){
  int w = 7;
  vector<int> wt = {1,3,4,5};
  vector<int> val = {1,4,5,7};
  int n = wt.size();
  vector<vector<int>> dp(n+1,vector<int>(w+1,0));
  for(int i=1;i<=n;i++){
    for(int j=0;j<=w;j++){
      if(wt[i-1]<=j){
        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]]/* this is about the max we get with weight left after
           subtracting current wight from it
           */, dp[i-1][j]);
        cout<<"{dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"} ";
      }else{
        dp[i][j] = dp[i-1][j];
        cout << "{dp[" << i << "][" << j << "] = " << dp[i][j] << "} ";
      }
    }
    cout<<endl;
  }
  cout<<dp[n][w]<<endl;
  return 0;
}
