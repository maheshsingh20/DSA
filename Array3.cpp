// #include<iostream>
// #include <vector>
// using namespace std;

// void knapSack(vector<int> value, vector<int> weight, int capacity, int n) {
//     vector<vector<int>> K(n+1, vector<int>(capacity+1, 0));
//     for(int i=0; i<=n; i++) {
//         for(int w=0; w<=capacity; w++) {
//             if(i == 0 || w == 0) {
//                 K[i][w] = 0;
//             }
//             else if(weight[i-1] <= w) {
//                 K[i][w] = max(value[i-1] + K[i-1][w - weight[i-1]], K[i-1][w]);
//             }
//             else {
//                 K[i][w] = K[i-1][w];
//             }
//         }
//     }
//     cout << K[n][capacity] << endl;
// }

// int main() {
//     vector<int> value = {12, 13, 26};
//     vector<int> weight = {20, 25, 30};
//     int capacity = 50;
//     int n = value.size();

//     knapSack(value, weight, capacity, n);  // Function call added
// }



// #include <iostream>
// #include <numeric>



// using namespace std;

// int sumofDigit(int n){
//     if(n<=9) return n;
//     int ans = 0;
//     ans+=n%10;
//     ans+=sumofDigit(n/10);
//     return ans;
// }

// int gcd(int a, int b){
//     if(b==0) return a;
//     return gcd(b, a%b);
// // }

// #include <iostream>
// #include <numeric> // Required for std::gcd
// using namespace std;

// int main() {
//     int a = 36, b = 60;
//     cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
//     return 0;
// }




#include <iostream> 
#include <vector>
#include<math.h>
#include <algorithm>
using namespace std;

int armstrongNumber(int n){
    int num1=n;
    vector<int>arr;
    while(num1>0){
        int k=num1%10;
        arr.push_back(k);
        num1/=10;
    }
    int sum=0;
    reverse(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        int currr=power(arr[i],arr.size());
        sum+=currr;
    }
    if(sum==n){
        return 1;
    }
    return sum;
}

int power(int a, int b){
    int curr=a;
    for(int i=1;i<=b;i++){
        curr*=a;
    }
    return curr;
}

// int maxdiff(vector<int> &arr){
//     int n = arr.size();
//     int minn=INT_MAX;
//     int maxx=INT_MIN;
//     for(int i=0; i<n; i++){
//         minn=min(minn, arr[i]);
//         maxx=max(maxx, arr[i]-minn);
//     }
//     return maxx;
// }

int main() {
    // vector<int> arr={2,3,10,6,4,8,1};
    // int n = arr.size();
    // cout<<maxdiff(arr)<<endl;

    cout<<armstrongNumber(10);
    return 0;
} 


#include <iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        
    }
}