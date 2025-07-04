#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

void printArray(vi &arr){
  for(auto i: arr){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main(){
  vi arr = {2, 2, 1, 5, 3, 3, 5, 6, 5, 6};
  sort(all(arr));
  auto it=unique(all(arr));
  arr.resize(it-arr.begin());
  printArray(arr);
  return 0;
}
