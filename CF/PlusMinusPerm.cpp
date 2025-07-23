#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    ll n, x, y;
    cin >> n >> x >> y;

    ll left = 1;
    ll right = n;
    ll lr = 0, rr = 0;

    for (ll i = x; i <= n; i += x)
    {
      if (i % y != 0)
      {
        rr += right;
        right--;
      }
    }

    for (ll j = y; j <= n; j += y)
    {
      if (j % x != 0)
      {
        lr += left;
        left++;
      }
    }

    cout << rr - lr << "\n";
  }
  return 0;
}
