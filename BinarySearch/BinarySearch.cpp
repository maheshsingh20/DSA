#include <bits/stdc++.h>
using namespace std;


int main(){
  int size;
  cin>>size;
  int *arr = new int[size];
  for (int i = 0; i < size;i++){
    cin>>arr[i];
  }
  int target;
  cin>>target;
  int low = 0;
  int high = size-1;
  while (high-low>1){
    int mid = low + (high - low) / 2;
    if(arr[mid]==target){
      cout<<mid<<endl;
      return 0;
    }else if(arr[mid]<target){
      low = mid+1;
    }else{
      high = mid;
    }
  }
  if(arr[low]==target){
    cout<<"found: "<<low<<endl;
  }else if(arr[high]==target){
    cout<<high<<endl;
  }else{
    cout<<"Not Found"<<endl;
  }
  return 0;
}
