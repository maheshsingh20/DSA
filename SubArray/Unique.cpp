#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cout << "Enter array size: ";
  cin >> n;
  cout<<"Enter array elements: "<<endl;
  int arr[n];
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }
  int ans = arr[0];
  for (int i = 1; i < n;i++){
    ans ^= arr[i];
  }
  cout << ans<<endl;
  return 0;
}