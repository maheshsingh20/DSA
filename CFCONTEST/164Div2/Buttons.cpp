#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fac(ll n, ll step){
  if(n==0)
    return 0;
  if(n==1){
    return n*step;
  }
  return (step * n) + fac(n - 1, step + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << fac(n-1,1ll)+n << "\n";
    return 0;
}
