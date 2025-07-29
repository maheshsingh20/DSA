#include <bits/stdc++.h>
using namespace std;

#define _sz(x) (int)(x).size()

const int N = 5000 + 20;
int dp[N][N];

inline bool possible(char a, char b) {
    return (a == '?' || b == '?' || a == b);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = _sz(s);
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (possible(s[i], s[j])) {
                    if (j - i <= 1)
                        dp[i][j] = 1;  // single or pair
                    else
                        dp[i][j] = 1 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] >= (j - i)) {
                    ans = max(ans, 2 * (j - i));
                }
            }
        }

        cout << ans << '\n';

        // Clear dp table for next test case
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = 0;
    }

    return 0;
}
