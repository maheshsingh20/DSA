#include <bits/stdc++.h>
using namespace std;
void help(vector<int> &arr){
    int n = arr.size();
    int carry =1;
    vector<int>res;
    for(int i=n-1; i>=0; i--){
        int sum = arr[i] + carry;
        int j = sum%10;
        res.push_back(j);
        carry = sum/10;
    }
    if(carry){
        res.push_back(carry);
    }
    reverse(res.begin(), res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}


int main(){
    vector<int> arr = {9,9,9,9};
    help(arr);
    return 0;
}