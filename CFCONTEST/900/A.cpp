#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    int k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int start = 0;
    int end = n-1;
    while(start+1<end){
      int mid = midpoint(start, end);
      if(a[mid]<k){
        start = mid+1;
      }else{
        end = mid;
      }
    }
    if(a[start]==k || a[end]==k){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
  return 0;
}
