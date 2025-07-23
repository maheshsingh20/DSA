#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr)
{
  int n = arr.size();
  vector<pair<int, int>> mp;
  for (int i = 0; i < n; i++)
  {
    mp.push_back({arr[i], i});
  }
  sort(mp.begin(), mp.end(), greater<>());

  vector<int> res;
  for (int i = 0; i < 3 && i < n; i++)
  {
    res.push_back(mp[i].second);
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++)
      cin >> c[i];

    vector<int> maxa = solve(a);
    vector<int> maxb = solve(b);
    vector<int> maxc = solve(c);

    int ans = 0;
    for (int i = 0; i < maxa.size(); i++)
    {
      for (int j = 0; j < maxb.size(); j++)
      {
        for (int k = 0; k < maxc.size(); k++)
        {
          int aa = maxa[i];
          int bb = maxb[j];
          int cc = maxc[k];
          if (aa == bb || bb == cc || cc == aa)
            continue;
          ans = max(ans, a[aa] + b[bb] + c[cc]);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
