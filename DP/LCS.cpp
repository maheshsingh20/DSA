#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str1 = "abcdefc", str2 = "abkcc";
  int n = str1.size(), m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        cout<<dp[i][j]<<" ";
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        cout << dp[i][j] << " ";
      }
    }
    cout<<endl;
  }
  return 0;
}
