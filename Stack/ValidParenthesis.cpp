#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str = ")((()()))";
  stack<char> st;
  for (int i = 0; i < str.length();i++){
    if(str[i]==')'){
      if(st.empty()){
        cout << "Invalid" << endl;
        return 0;
      }else{
        st.pop();
      }
    }
    if(str[i]=='(') st.push(str[i]);
  }
  if(st.empty())
    cout << "Valid" << endl;
  else
    cout << "Invalid" << endl;
  return 0;
}
