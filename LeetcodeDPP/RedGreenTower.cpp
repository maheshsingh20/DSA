#include <bits/stdc++.h>
using namespace std;


int help(int red, int green){
    int total=red+green;
    int k=0;
    while((k+1)*(k+2)/2<=total){
        k++;
    }
    vector<vector<int>> dp(k+1,vector<int>(2,0));
    dp[0][0]=1;
    
    for(int i=2;i<=k;i++){
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        dp[i][j]=dp[i][j]%1000000007;

    }

}

int main(){
    int red,green;
    cin>>red>>green;
    cout<<help(red,green)<<endl;
    return 0;
}