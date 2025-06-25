#include <bits/stdc++.h>
using namespace std;

int countBalancedIndices(vector<int>& a) {
    int n = a.size();
    vector<int> evenPrefix(n, 0), oddPrefix(n, 0);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            evenPrefix[i] = a[i];
            oddPrefix[i] = 0;
        } else {
            evenPrefix[i] = evenPrefix[i - 1];
            oddPrefix[i] = oddPrefix[i - 1];
            if (i % 2 == 0)
                evenPrefix[i] += a[i];
            else
                oddPrefix[i] += a[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int evenLeft = (i > 0) ? evenPrefix[i - 1] : 0;
        int oddLeft = (i > 0) ? oddPrefix[i - 1] : 0;

        int evenRight = oddPrefix[n - 1] - oddPrefix[i];
        int oddRight = evenPrefix[n - 1] - evenPrefix[i];

        if (evenLeft + evenRight == oddLeft + oddRight)
            count++;
    }

    return count;
}

int main() {
    vector<int> arr = {1,1,1};
    cout << countBalancedIndices(arr) << endl;
    return 0;
}
