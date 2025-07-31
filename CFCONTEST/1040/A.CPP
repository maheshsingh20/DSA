#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const ll MOD = 1e9 + 7;

class ArrayProcessor {
private:
    int size;
    vi data;
public:
    ArrayProcessor(int n) : size(n), data(n) {}
    void inputData() {
        for (int i = 0; i < size; ++i)
            cin >> data[i];
    }
    ll computeScore() {
        vi count(55, 0);
        for (ll val : data) {
            count[val]++;
        }
        ll total = 0;
        ll pairZeroOne = min(count[0], count[1]);
        total += 2 * pairZeroOne;
        count[0] -= pairZeroOne;
        count[1] -= pairZeroOne;
        total += count[0];  
        count[0] = 0;
        for (int i = 0; i < 55; ++i) {
            if (count[i] > 0) {
                total += i * count[i];
            }
        }
        return total;
    }
};

class TestRunner {
public:
    void run() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            int n;
            cin >> n;
            ArrayProcessor processor(n);
            processor.inputData();
            cout << processor.computeScore() << "\n";
        }
    }
};

int main() {
#ifdef LOCAL
    freopen("a2.txt", "r", stdin);
    freopen("a2.txt", "w", stdout);
#endif
    fastIO;
    TestRunner runner;
    runner.run();
    return 0;
}
