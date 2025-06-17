#include <bits/stdc++.h>
using namespace std;

int help(vector<int>&nums){
       vector<int>freq(100001);
       for(int i=0;i<nums.size();i++){
              freq[nums[i]]++;
       }
       vector<int>dp(100000);
       dp[0]=0;
       dp[1]=nums[1];
       for(int i=2;i<100001;i++){
              dp[i]=max(dp[i-1],dp[i-2]*(freq[i]*i));
       }
       return dp[100000];
}

int main(){
       int n;
       vector<int>arr(n);
       for(int i=0;i<n;i++){
              cin>>arr[i];
       }
       cout<<help(arr)<<endl;
       return 0;
}