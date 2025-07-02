#include <bits/stdc++.h>
using namespace std;

typedef vector<int> arr;
typedef vector<arr> mat;

mat insertInterval(mat& intervals, arr newInterval) {
    mat res;
    int i = 0;
    int n = intervals.size();

    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    mat intervals = {{1, 3}, {6, 9}};
    arr newInterval = {2, 5};

    mat result = insertInterval(intervals, newInterval);

    for (auto& it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}

