#include <iostream>
#include <vector>
using namespace std;

vector<long long> help(long long n){
    vector<long long> ans;
    ans.push_back(n);
    while (n!=1){
        if(n%2==0){
            ans.push_back(n/2);
            n=n/2;
        }else{
            ans.push_back(n*3+1);
            n=n*3+1;
        }
    }
    return ans;
}


int main(){
    long long n;
    cin >> n;
    vector<long long> res = help(n);
    for(int i=0;i<res.size();i++){
        cout << res[i] <<" ";
    }
    return 0;
}