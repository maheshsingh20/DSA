#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_set<char> st(s.begin(), s.end());
  int totalUnique = st.size();
  unordered_map<char, int> mp;
  int start = 0;
  int ans = INT_MAX;
  for (int end = 0; end < n; ++end)
  {
    mp[s[end]]++;
    while (mp.size() == totalUnique)
    {
      ans = min(ans, end - start + 1);
      mp[s[start]]--;
      if (mp[s[start]] == 0)
      {
        mp.erase(s[start]);
      }
      start++;
    }
  }

  cout << ans << "\n";
  return 0;
}
