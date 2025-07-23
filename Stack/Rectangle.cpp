#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {5, 4, 3, 2, 6, 5, 0, 7, 6,8 };
  stack <int> st;
  int Area = 0;
  int n = arr.size();
  for (int i = 0; i <= n;i++){
    int curr= (i == n) ? 0 : arr[i];
    while(!st.empty() && arr[st.top()]>curr){
      int height = arr[st.top()];
      st.pop();
      int width = (st.empty()) ? 1 : i - st.top() - 1;
      Area=max(Area,height*width);
    }
    st.push(i);
  }
  cout << Area << endl;
  return 0;
}
