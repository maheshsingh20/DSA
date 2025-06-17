#include <bits/stdc++.h>
using namespace std;

void solve(int k){
    string s;
    cin>>s;
    int n = s.length();
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i+1]){
            count++;
        }
    }
    if(count<=k){
        
    }
}

int main(){
    int t, k;
    cin>>t>>k;
    while(t--){
        solve(k);
    }
    return 0;
}