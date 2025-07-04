#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int days;
  cin >> days;
  sort(a.begin(), a.end());

  while (days--)
  {
    int target;
    cin >> target;

    // Option 1: Manual Binary Search (corrected)
    int start = 0, end = n - 1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (a[mid] <= target)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
    cout << start << '\n';

    // OR Option 2: STL one-liner
    // cout << upper_bound(a.begin(), a.end(), target) - a.begin() << '\n';
  }

  return 0;
}
