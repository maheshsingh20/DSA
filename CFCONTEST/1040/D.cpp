#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
class FenwickTree {
private:
    int size;
    vi tree;
public:
    FenwickTree(int n = 0) : size(n), tree(n + 1, 0) {}
    void initialize(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    void update(int index) {
        while (index <= size) {
            tree[index]++;
            index += index & -index;
        }
    }
    ll query(int index) {
        ll result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
};
class InversionCalculator {
public:
    void solveCase() {
        int length;
        cin >> length;
        vi sequence(length + 1);
        for (int i = 1; i <= length; ++i)
            cin >> sequence[i];
        vi rightInversions(length + 1, 0);
        vi greaterToLeft(length + 1, 0);
        FenwickTree bit(length);
        ll totalInversions = 0;
        bit.initialize(length);
        for (int i = length; i >= 1; --i) {
            rightInversions[i] = bit.query(sequence[i] - 1);
            totalInversions += rightInversions[i];
            bit.update(sequence[i]);
        }
        bit.initialize(length);
        for (int i = 1; i <= length; ++i) {
            greaterToLeft[i] = (i - 1) - bit.query(sequence[i]);
            bit.update(sequence[i]);
        }
        ll negativeBalanceSum = 0;
        for (int i = 1; i <= length; ++i) {
            ll balance = (length - i) - rightInversions[i] - greaterToLeft[i];
            if (balance < 0) {
                negativeBalanceSum += balance;
            }
        }
        ll finalAnswer = totalInversions + negativeBalanceSum;
        cout << finalAnswer << " \n";
    }
};
class Runner {
public:
    void execute() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            InversionCalculator solver;
            solver.solveCase();
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Runner app;
    app.execute();
    return 0;
}
