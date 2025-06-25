#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int start=0;
        int end=n-1;
        bool s=true;
        for(int i=1;i<=n;i++){
            if(s){
                v[start]=i;
                start++;
                s=false;
            }else{
                v[end]=i;
                end--;
                s=true;
            }
        }
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}