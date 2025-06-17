#include <bits/stdc++.h>
using namespace std;

/* starting and ending index where current subarray consist sum equal to given value */

pair<int,int> isFoundSubArray(vector<int>&arr, int key){
    int start=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>key){
            while(sum>key){
                sum-=arr[start];
                start++;
            }
        }
        if(sum==key){
            return {start,i};
        }
    }
    return {-1,-1};
}

int main(){
    vector<int> arr={1,3,2,5,1,1,2,3};
    pair<int,int> ans=isFoundSubArray(arr,14);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}