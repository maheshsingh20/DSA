#include <bits/stdc++.h>
using namespace std;

/* Manacher’s Algorithm */

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cout << "Enter a string: ";
  cin >> s;

  // Step 1: Transform the string
  string t = "^#";
  for (char ch : s)
  {
    t += ch;
    t += "#";
  }
  t += "$";

  int m = t.size();
  vector<int> p(m, 0);
  int c = 0, r = 0;

  for (int i = 1; i < m - 1; i++)
  {
    int mirror = 2 * c - i;

    cout << "i = " << i << " (" << t[i] << "), R = " << r << ", C = " << c;
    cout << ", mirror = " << mirror;

    // Case 1: i is inside R
    if (i < r)
    {
      p[i] = min(r - i, p[mirror]);
      cout << ", P[i] from mirror = " << p[i];
    }

    // Expand palindrome centered at i
    while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
    {
      p[i]++;
    }

    cout << ", Expanded P[i] = " << p[i];

    // If palindrome at i expands beyond r, adjust center c and boundary r
    if (i + p[i] > r)
    {
      c = i;
      r = i + p[i];
      cout << ", Updated C = " << c << ", R = " << r;
    }

    cout << endl;
  }

  // Find longest palindromic substring
  int maxLen = 0, centerIndex = 0;
  for (int i = 1; i < m - 1; i++)
  {
    if (p[i] > maxLen)
    {
      maxLen = p[i];
      centerIndex = i;
    }
  }

  int start = (centerIndex - maxLen) / 2;
  cout << "\nLongest Palindromic Substring: " << s.substr(start, maxLen) << endl;

  return 0;
}
