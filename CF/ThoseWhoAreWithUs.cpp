#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    int max_val = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
        max_val = max(max_val, a[i][j]);
      }

    // store row and column max counts
    vector<int> row_cnt(n, 0), col_cnt(m, 0);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == max_val)
        {
          row_cnt[i]++;
          col_cnt[j]++;
        }

    int max_occur = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        int total = row_cnt[i] + col_cnt[j];
        if (a[i][j] == max_val)
          total--; // counted twice
        max_occur = max(max_occur, total);
      }

    // If all max values can be reduced
    int count_max = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == max_val)
          count_max++;

    if (max_occur >= count_max)
      cout << max_val - 1 << '\n';
    else
      cout << max_val << '\n';
  }
  return 0;
}
