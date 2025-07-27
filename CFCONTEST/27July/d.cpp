#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sti stack<int>
#define rep(i,s,end) for (int i = s;i<=end;i++)
void solve(){
  int curr;
  cin >> curr;
  int arr[curr + 2];
  int arr2[curr + 2];
  for (int i = 1; i <= curr;i++){
    cin >> arr[i];
  }
  sti ss;
  rep(i,1,curr){
    while(!ss.empty() && arr2[ss.top()]<arr[i]){
      arr2[ss.top()] = i;
      ss.pop();
    }
    ss.push(i);
  }
  while(!ss.empty()){
    arr2[ss.top()] = curr + 1;
    ss.pop();
  }
  ll result = 0;
  rep(i,1,curr){
    result += (ll)i * (arr2[i] - i);
  }
  cout << res << "\n";
}
int main(){
  ios_base::sync_with_stdio(0);
  int test_case;
  cin >> test_case;
  while(t--){
    solve;
  }
  return 0;
}