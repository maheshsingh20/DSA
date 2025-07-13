#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<ll> a(n);
    int j = 0;
    a[j++] = n + 1;
    a[j++] = n + 2;
    while (j < n)
    {
      a[j++] =(a[j - 1] + a[j - 2] - 1);
    }
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
