#include <bits/stdc++.h>
using namespace std;
int maxx=1e5+7;
int mod=1e9+7;
int dp[100005][2];

void precompute(int k){
    dp[0][0]=1;
    dp[0][1]=0;
    for(size_t i=0;i<maxx;i++){
        dp[i][0]=dp[i-1][0]%mod;
        if(i>=k){
            dp[i][0]=(dp[i][0]+dp[i-k][0])%mod;
        }
    }
}

int main(){
    int t,k;
    cin>>t>>k;
    precompute(k);
    while(t--){
        int a,b;
        cin>>a>>b;

    }

}