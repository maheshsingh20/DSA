#include <bits/stdc++.h>
using namespace std;

class Segment
{
public:
  vector<int> seg;

  Segment(int n)
  {
    seg.resize(n);
  }

  void build(vector<int> &arr, int l, int r, int i)
  {
    if (l == r)
    {
      seg[i] = pow(arr[l],2);
    }
    else
    {
      int mid = (l + r) / 2;
      build(arr, l, mid, 2 * i + 1);
      build(arr, mid + 1, r, 2 * i + 2);
      seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
  }
  int query(int ql, int qr, int l, int r, int i)
  {
    if (ql > qr || ql > r || qr < l)
      return 0;
    if (ql <= l && qr >= r)
      return seg[i];
    int mid = (l + r) / 2;
    int left = query(ql, qr, l, mid, 2 * i + 1);
    int right = query(ql, qr, mid + 1, r, 2 * i + 2);
    return left + right;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {4, 3, 5, 7, 8, 5, 2, 9};
  int n = arr.size();
  Segment s(4 * n);
  s.build(arr, 0, n - 1, 0);
  cout << s.query(0, 3, 0, n - 1, 0) << endl;

  return 0;
}
