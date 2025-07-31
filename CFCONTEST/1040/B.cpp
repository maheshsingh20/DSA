#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

class DistributionSolver {
private:
    ll n, targetSum;
    vi inputArray;
public:
    void readInput() {
        cin >> n >> targetSum;
        inputArray.resize(n);
        for (ll &val : inputArray)
            cin >> val;
    }
    void process() {
        ll totalSum = 0;
        ll countZero = 0, countOne = 0, countTwo = 0;
        for (ll val : inputArray) {
            totalSum += val;
            if (val == 0) countZero++;
            else if (val == 1) countOne++;
            else if (val == 2) countTwo++;
        }
        ll remaining = targetSum - totalSum;
        if (remaining < 0 || remaining == 1) {
            bool space = false;
            for (int i = 0; i < countZero; ++i)
                printWithSpace(0, space);
            for (int i = 0; i < countTwo; ++i)
                printWithSpace(2, space);
            for (int i = 0; i < countOne; ++i)
                printWithSpace(1, space);
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

private:
    void printWithSpace(ll val, bool &spacePrinted) {
        if (spacePrinted) cout << " ";
        cout << val;
        spacePrinted = true;
    }
};

class ProblemRunner {
public:
    void execute() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            DistributionSolver solver;
            solver.readInput();
            solver.process();
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ProblemRunner runner;
    runner.execute();
    return 0;
}
