#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int amount = 11;
  vector<int> coins = {1, 2, 5};
  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++)
  {
    for (int j = 0; j < coins.size(); j++)
    {
      if (coins[j] <= i)
      {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }else{
        dp[i] = dp[i];
      }
    }
  }
}
