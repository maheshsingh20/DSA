#include <iostream>
#include <vector>
using namespace std;

int help(vector<int>&nums){
    int n = nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int cd;
        cin>>cd;
        nums.push_back(cd);
    }
    int res=(n*(n+1))/2;
    cout<<res-help(nums);
    return 0;
}