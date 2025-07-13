#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Custom GCD function with different structure
ll calculate_gcd(ll u, ll v)
{
  while (v != 0)
  {
    ll temp = u % v;
    u = v;
    v = temp;
  }
  return u;
}

// Computes the adjusted LCM factor under __int128 to prevent overflow
ll combine_factors(ll base, ll factor)
{
  ll shared = calculate_gcd(base, factor);
  __int128 expanded = (__int128)(base / shared) * factor;
  return (ll)expanded;
}

// Handles each test case
ll determine_x(const vector<ll> &arr)
{
  ll x = 1;
  int sz = arr.size();

  for (int k = 0; k + 1 < sz; ++k)
  {
    if (arr[k] == 0)
      continue;

    if (arr[k + 1] % arr[k] != 0)
    {
      ll part_gcd = calculate_gcd(arr[k], arr[k + 1]);
      ll quotient = arr[k] / part_gcd;
      x = combine_factors(x, quotient);
    }
  }

  return x;
}

void process_input()
{
  int test_cases;
  cin >> test_cases;

  while (test_cases--)
  {
    int count;
    cin >> count;

    vector<ll> sequence(count);
    for (int i = 0; i < count; ++i)
    {
      cin >> sequence[i];
    }

    ll result = determine_x(sequence);
    cout << result << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  process_input();

  return 0;
}
