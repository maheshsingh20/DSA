#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int start = 0;
    long long curr = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      curr += (long long)a[i];
      while (curr > m || a[i]-a[start]>1)
      {
        curr -= a[start];
        start++;
      }
      ans = max(ans, curr);
    }
    cout << ans << '\n';
  }
  return 0;
}
