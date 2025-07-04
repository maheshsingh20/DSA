#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;
  while (test_cases--)
  {
    int n;
    cin >> n;
    string str;
    cin >> str;

    map<int, int> freq;
    freq[0] = 1;

    int sum = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
      sum += str[i] - '0';
      int key = sum - (i + 1);
      ans += freq[key];
      freq[key]++;
    }

    cout << ans << "\n";
  }

  return 0;
}
