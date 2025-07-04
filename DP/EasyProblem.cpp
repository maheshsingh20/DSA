#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }
  int dp[n + 1][4];
  dp[0][0] = 0;
  dp[0][1] = INF;
  dp[0][2] = INF;
  dp[0][3] = INF;
  for (int i = 1; i <= n; i++)
  {
    if (str[i - 1] == 'h')
    {
      dp[i][0] = dp[i - 1][0] + arr[i - 1];
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
    }
    else if (str[i - 1] == 'a')
    {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + arr[i - 1];
      dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]);
      dp[i][3] = dp[i - 1][3];
    }
    else if (str[i - 1] == 'r')
    {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2] + arr[i - 1];
      dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
    }
    else if (str[i - 1] == 'd')
    {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3] + arr[i - 1];
    }
    else
    {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
    }
  }
  cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << endl;
  return 0;
}
