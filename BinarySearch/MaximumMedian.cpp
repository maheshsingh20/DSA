#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int mid = n / 2;
  int curr = a[mid];

  while (k > 0)
  {
    curr++;
    auto lb = lower_bound(a.begin() + mid, a.end(), curr);
    int count = lb - (a.begin() + mid);
    if (count == 0)
      continue;
    int total_needed = count;
    if (k >= total_needed)
    {
      k -= total_needed;
    }
    else
    {
      curr--;
      curr += k / count;
      cout << curr << "\n";
      return 0;
    }
  }
  cout << curr << "\n";
  return 0;
}
