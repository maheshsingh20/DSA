#include <bits/stdc++.h>
using namespace std;
/*Next greater Element

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  stack<int> st;
  vector<int> array = {3,4,5,6,6,7,7,8,9};
  int key = 9;
  for (int i = 0; i < array.size();i++){
    if(array[i]>key){
      if(st.empty()){
        st.push(i);
      }else{
        if (array[i] < array[st.top()])
        {
          while (!st.empty() && array[st.top()]>array[i]){
            st.pop();
          }
          st.push(i);
        }
      }
    }
  }
  if(st.empty())
    cout << "-1" << endl;
  while(!st.empty()){
    cout << array[st.top()] << endl;
    st.pop();
  }
  return 0;
}

*/

/*latest previous number
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  stack<int> st;
  vector<int> arr = {5, 4, 3, 5, 2, 8, 7, 4, 2};
  int key = 4;
  int n = arr.size();
  for (int i = 0; i < n;i++){
    if(arr[i]<key){
      while(!st.empty() && arr[st.top()]<arr[i]){
        st.pop();
      }
      st.push(i);
    }
  }
  if(st.empty())cout<<"-1"<<endl;
  while(!st.empty()){
    if(st.size()==1)
      cout << arr[st.top()] << endl;
    st.pop();
  }
  return 0;
}

*/


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
}
