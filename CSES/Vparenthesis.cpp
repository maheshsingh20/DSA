#include <bits/stdc++.h>
using namespace std;

bool isValid(string_view str){
    int n=str.size();
    stack<char>st;
    int open=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            st.push(str[i]);
        }else{
            if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s="()(()";
    if(isValid(s)){
        cout<<"YES";
    }else{
        cout<<"No";
    }
    return 0;
}