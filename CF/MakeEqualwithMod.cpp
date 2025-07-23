#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, s, end) for (int i = s; i < end; i++)

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
    vector<ll> str(n);
    rep(i, 0, n)
    {
      cin >> str[i];
    }

    bool found = false;
    rep(i, 1, 61)
    {
      ll k = 1LL << i;
      unordered_set<ll> st; // ✅ fix: moved here to reset each time
      rep(j, 0, n)
      {
        st.insert(str[j] % k);
      }
      if (st.size() == 2)
      {
        cout << k << "\n";
        found = true;
        break;
      }
    }

    if (!found)
      cout << "-1\n"; // fallback if no such k found
  }
  return 0;
}
