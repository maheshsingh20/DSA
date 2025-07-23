#include <bits/stdc++.h>
constexpr int64_t MOD = 998244353;
constexpr int MAX = 200005;
class MathToolkit
{
  std::vector<int64_t> fact, invFact;
  int64_t modExp(int64_t base, int64_t exp) const
  {
    int64_t result = 1;
    while (exp)
    {
      if (exp & 1)
        result = result * base % MOD;
      base = base * base % MOD;
      exp >>= 1;
    }
    return result;
  }
public:
  MathToolkit(int limit)
  {
    fact.resize(limit + 1, 1);
    invFact.resize(limit + 1, 1);
    for (int i = 1; i <= limit; ++i)
      fact[i] = fact[i - 1] * i % MOD;
    invFact[limit] = modExp(fact[limit], MOD - 2);
    for (int i = limit - 1; i >= 1; --i)
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }
  int64_t nCr(int n, int r) const
  {
    if (r < 0 || r > n)
      return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
  }
};
class ComplementarySetSolver
{
  MathToolkit math;
  std::unordered_map<int, std::vector<int64_t>> memo;
public:
  ComplementarySetSolver(int maxLimit) : math(maxLimit) {}
  int64_t solve(int n, int x)
  {
    if (n == 1)
      return x % MOD;
    if (n > x)
      return 0;
    if (!memo.count(n))
    {
      std::vector<int64_t> cache(x + 1, 0);
      for (int last = n; last <= x; ++last)
      {
        int64_t targetSum = 1LL * (n - 1) * last;
        int64_t minSum = 1LL * n * (n - 1) / 2;
        int64_t maxSum = 1LL * (last - 1) * (last) / 2;
        if (targetSum < minSum || targetSum > maxSum)
          continue;
        cache[last] = math.nCr(last - 1, n - 1);
      }
      memo[n] = std::move(cache);
    }
    int64_t total = 0;
    const auto &dp = memo[n];
    for (int i = n; i <= x; ++i)
      total = (total + dp[i]) % MOD;
    return total;
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  ComplementarySetSolver solver(MAX);
  while (t--)
  {
    int n, x;
    std::cin >> n >> x;
    std::cout << solver.solve(n, x) << '\n';
  }
  return 0;
}
