#include <bits/stdc++.h>
using namespace std;
int main(){
  int n=7;
  int arr[n]={1,2,-3,4,-2,3,1};
  int sum=0;
  unordered_map<int,int> m;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0 || m.find(sum)!=m.end()){
      cout<<"Subarray with sum 0 exists"<<endl;
      return 0;
    }
  }
  cout<<"No subarray with sum 0 exists"<<endl;
  return 0;
}
