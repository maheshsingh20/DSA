#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int prev = nums[j] / 2;
            int next = nums[j] * 2;
            if (mp.find(prev) == mp.end() || mp.find(next) == mp.end()) {
                continue;
            }
            int preCount = lower_bound(mp[prev].begin(), mp[prev].end(), j) - mp[prev].begin();
            int postCount = mp[next].end() - upper_bound(mp[next].begin(), mp[next].end(), j);
            ans = (ans + (preCount * postCount) % mod) % mod;
        }
        return ans;
    }
};
int main(){

}