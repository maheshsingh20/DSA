//LONGEST INCREASING SUSBEQUENCE

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

void printingLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> LIS;
    while (maxIndex != -1) {
        LIS.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }
    reverse(LIS.begin(), LIS.end());

    for (auto i : LIS) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    printingLIS(nums);
    return 0;
}