#include <bits/stdc++.h>
using namespace std;

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
    vector<tuple<int, int, int>> store;

    for (int i = 1; i + 2 <= n; i++)
    {
      store.emplace_back(i, i + 1, i + 2);
    }

    cout << store.size() << "\n";
    for (auto &[a, b, c] : store)
    {
      cout << a << " " << b << " " << c << "\n";
    }
  }

  return 0;
}
