#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int n;
	cin >> n;
	vector<int> b(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	vector<bool> dp(n + 1, false);
	dp[0] = true;

	for (int i = 1; i <= n; i++) {
		if (i + b[i] <= n && dp[i - 1]) {
			dp[i + b[i]] = true;
		}
		if (i - b[i] - 1 >= 0 && dp[i - b[i] - 1]) {
			dp[i] = true;
		}
	}

	cout << (dp[n] ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
