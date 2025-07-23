#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();
  string t = s;
  reverse(t.begin(), t.end());

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  cout << "Filling DP Table for LPS (using LCS of s and reverse(s)):\n";
  cout << "s = " << s << ", reverse = " << t << "\n\n";

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout<<s[i-1]<<" "<<t[j-1]<<endl;
      if (s[i - 1] == t[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        cout << "dp[" << i << "][" << j << "] (match '" << s[i - 1] << "') = 1 + dp[" << i - 1 << "][" << j - 1 << "] = " << dp[i][j] << "\n";
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        cout << "dp[" << i << "][" << j << "] (no match '" << s[i - 1] << "' vs '" << t[j - 1] << "') = max(dp[" << i - 1 << "][" << j << "] = " << dp[i - 1][j]
             << ", dp[" << i << "][" << j - 1 << "] = " << dp[i][j - 1] << ") = " << dp[i][j] << "\n";
      }
    }
  }

  cout << "\nLength of Longest Palindromic Subsequence: " << dp[n][n] << endl;
  return 0;
}
