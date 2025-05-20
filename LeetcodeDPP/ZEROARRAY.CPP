#include <bits/stdc++.h>
using namespace std;

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> diff(n+1, 0);
    for (int i = 0; i < queries.size(); i++){
        int lower = queries[i][0];
        int upper = queries[i][1];
        diff[lower] -= 1;
        diff[upper + 1] += 1;
    }
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += diff[i];
        if (nums[i] == 0)
            continue;
        nums[i] += curr;
    }
    bool isValid = true;
    for (int i=0; i<n; i++)
    {
        if (nums[i] != 0)
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

int main()
{
    vector<int> arr = {1, 0, 1};
    vector<vector<int>> querry = {{0, 2}};
    if(isZeroArray(arr, querry)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}