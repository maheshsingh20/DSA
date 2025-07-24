#include <iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 8;
  int arr[n]={4,5,6,7,-1,0,2,3};
  int low = 0;
  int high = n-1;
  while(low+1<high){
    int mid=low+(high-low)/2;
    if(arr[mid]>arr[high]){
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
  cout<<min(arr[low],arr[high])<<endl;
  return 0;
}
