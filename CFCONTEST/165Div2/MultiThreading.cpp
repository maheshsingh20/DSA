#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      cnt++;
    } else {
      break;
    }
  }
  cout << n - cnt << "\n";
  return 0;
}