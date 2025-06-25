#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
      int minimumAverageDifference(vector<int>& nums) {
          int n = nums.size();
          int diff = INT_MAX;
          int ans = 0;
          vector<long long> prefix(n);
          prefix[0] = nums[0];

          for (int i = 1; i < n; i++) {
              prefix[i] = prefix[i - 1] + nums[i];
          }

          for (int i = 0; i < n; i++) {
              int left = prefix[i] / (i + 1);
              int right = 0;
              if (i != n - 1) {
                  right = (prefix[n - 1] - prefix[i]) / (n - i - 1);
              }
              int c = abs(left - right);
              if (c < diff) {
                  diff = c;
                  ans = i;
              }
          }
          return ans;
      }
  };
