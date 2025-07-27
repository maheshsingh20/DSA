#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=7; 
  int target=6;
  int arr[n]={1,3,4,5,1,3,2};
  unordered_map<int,int>mp;
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==target){
      cout<<"found at index "<<0<<i<<endl;
    }
    if(mp.find(sum-target)!=mp.end()){
      cout<<"found at index "<<mp[sum-target]<<i<<endl;
    }
    mp[sum]=i;
  }
  return 0;
}
