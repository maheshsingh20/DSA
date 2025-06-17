#include <bits/stdc++.h>
using namespace std;

struct compar{
    bool operator()(vector<int>a, vector<int>b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
};

int countMinQueries(vector<int> arr, vector<vector<int>> queries){
    int n=queries.size();
    int m=arr.size();
    int ans=0;
    int lastRange=0;
    for(int i=0;i<n;i++){
        if(queries[i][0]==lastRange){
            lastRange=queries[i][1];
            
        }
    }
}

int main(){
    vector<int> arr={1,1,1,1};
    vector<vector<int>> queries={{1,3},{0,2},{1,3},{1,2}};
    sort(queries.begin(), queries.end(), compar());
    if(queries[0][0]!=0){
        cout<<"-1"<<endl;
    }

}