// #include <bits/stdc++.h>
// using namespace std;



// int main(){
//     vector<int> arr = {9,4,-2,-1,5,0,-5,-3,2};
//     int n = arr.size();
//     int negativeCount=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<0){
//             negativeCount++;
//         }
//     }
//     int positiveCount = n-negativeCount;
//     int pos=0;
//     int neg=1;
//     vector<int> ans(n);
//     for(int i=0;i<n;i++){
//         if(arr[i]>=0){
//             ans[pos]=arr[i];
//             positiveCount--;
//             if(negativeCount==0){
//                 pos+=1;
//             }else{
//                 pos+=2;
//             }
//         }
//         else{
//             ans[neg]=arr[i];
//             negativeCount--;
//             if(positiveCount==0){
//                 neg+=1;
//             }else{
//                 neg+=2;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;



//suffix array
int main(){
    vector<int> arr = {1,5,4,9,2,3,4,2};
    int n=arr.size();
    vector<int> suffixArray(n);
    suffixArray[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixArray[i]=arr[i]+suffixArray[i+1];
    }
    for(int i=0;i<n;i++){
        cout<<suffixArray[i]<<" ";
    }
    int mValue=*max_element(suffixArray.begin(),suffixArray.end());
    int maxx=max_element(suffixArray.begin(),suffixArray.end())-suffixArray.begin();
    cout<<endl<<maxx;
    return 0;
}