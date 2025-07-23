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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    int ans = 0;

    // First Operation: Reduce elements from minIdx onwards
    int minn = *min_element(a.begin(), a.end());
    int minIdx = min_element(a.begin(), a.end()) - a.begin();
    int h = minn / (n - minIdx);

    for (int i = minIdx; i < n; i++)
    {
      a[i] -= h;
    }

    // Second Operation: Reduce elements up to minIdx
    minn = *min_element(a.begin(), a.end());
    minIdx = min_element(a.begin(), a.end()) - a.begin();
    h = (minIdx == 0) ? 0 : minn / (minIdx); // avoid divide by zero

    for (int i = 0; i < minIdx; i++)
    {
      a[i] -= h;
    }

    // Check if all values are now zero
    bool allZero = all_of(a.begin(), a.end(), [](int x)
                          { return x == 0; });

    if (allZero)
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
