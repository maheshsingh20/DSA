/*
#include <bits/stdc++.h>
using namespace std;

int greatestElement(vector<int>arr){
    unordered_set<int> st(arr.begin(),arr.end());
    int ans=INT_MIN;
    for(size_t i=0;i<arr.size();i++){
        for(size_t j=0;j<arr.size();j++){
            if(st.find(arr[i]*arr[j])!=st.end() && i!=j){
                ans=max(ans,arr[i]*arr[j]);
            }
        }
    }
    return (ans==INT_MIN)?-1:ans;    
}

int main(){
    vector<int>arr={2,7,4,5,6};
    cout<<greatestElement(arr)<<endl;
    return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;

/**/

int main(){

}