#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int zeroOneKnapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int num_items = weights.size();
    // DP table where dp[i][w] represents maximum value for first i items with capacity w
    vector<vector<int>> dp(num_items + 1, vector<int>(capacity + 1, 0));

    for (int item = 1; item <= num_items; ++item) {
        for (int current_cap = 1; current_cap <= capacity; ++current_cap) {
            // If current item's weight exceeds current capacity, can't include it
            if (weights[item - 1] > current_cap) {
                dp[item][current_cap] = dp[item - 1][current_cap];
            } else {
                // Choose between including or excluding the current item
                int exclude = dp[item - 1][current_cap];
                int include = values[item - 1] + dp[item - 1][current_cap - weights[item - 1]];
                dp[item][current_cap] = max(exclude, include);
            }
        }
    }

    return dp[num_items][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int max_value = zeroOneKnapsack(weights, values, capacity);
    cout << "Maximum value achievable: " << max_value << endl;

    return 0;
}



*/

//House Robber -->> 1

int rob(vector<int>& nums, int n){
    if(n>=nums.size()) return 0;
    int take= rob(nums, n+2)+nums[n];
    int notTake = rob(nums, n+1);
    return max(take, notTake);
}
int rob(vector<int> &nums){
    int n = nums.size();
    return rob(nums, 0);
}


/*  Matrix Chain Multiplication  */  



int main()
{
    // vector<int> values = {60, 100, 120};
    // vector<int> weights = {10, 20, 30};
    // int W = 50;
    // int n = values.size();

    // cout << "Maximum value in knapsack = " << knapsack_01(W, weights, values, n) << endl;
    // vector<int> nums = {2,1,3,2};
    // cout<<rob(nums);

    
    return 0;
}