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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        cnt++;
      }
    }
    if (cnt <= k)
    {
      cout << "Alice" << endl;
    }
    else
    {
      if (2 * k > n)
      {
        cout << "Alice" << endl;
      }
      else
      {
        cout << "Bob" << endl;
      }
    }
  }
  return 0;
}
