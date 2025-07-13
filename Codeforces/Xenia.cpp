#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> seg;
  Solution(int n)
  {
    seg.resize(4 * n);
  }

  void build(vector<int> &a, int v, int tl, int tr, bool isOr)
  {
    if (tl == tr)
    {
      seg[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm, !isOr);
    build(a, v * 2 + 1, tm + 1, tr, !isOr);
    if (isOr)
      seg[v] = seg[v * 2] | seg[v * 2 + 1];
    else
      seg[v] = seg[v * 2] ^ seg[v * 2 + 1];
  }

  void update(int v, int tl, int tr, int pos, int new_val, bool isOr)
  {
    if (tl == tr)
    {
      seg[v] = new_val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val, !isOr);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val, !isOr);

    if (isOr)
      seg[v] = seg[v * 2] | seg[v * 2 + 1];
    else
      seg[v] = seg[v * 2] ^ seg[v * 2 + 1];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, q;
  cin >> k >> q;
  int size = 1 << k;

  vector<int> a(size);
  for (int i = 0; i < size; i++)
  {
    cin >> a[i];
  }

  Solution S(size);
  bool isOr = (k % 2 == 1);
  S.build(a, 1, 0, size - 1, isOr);

  while (q--)
  {
    int pos, val;
    cin >> pos >> val;
    S.update(1, 0, size - 1, pos - 1, val, isOr);
    cout << S.seg[1] << "\n";
  }
  return 0;
}
