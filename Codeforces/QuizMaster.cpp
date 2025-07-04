#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_case;
  cin >> test_case;
  while(test_case--){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    int ans = INT_MAX;
    vector<int> freq(m + 1, 0);
    int covered_topic = 0;
    //find divisors and add
    int start = 0;
    for (int i = 0; i < n;i++){
      int curr = v[i];
      for (int j = 1; j <= curr;j++){
        if(curr%j==0){
          freq[j]++;
          if(freq[j] == 1){
            covered_topic++;
            if(covered_topic == m){
              ans = min(ans, i - start + 1);
              while(covered_topic>=m){
                int nn = v[start];
                for (int k = 1; k<= nn;k++){
                  if(nn%k==0){
                    freq[k]--;
                    if(freq[k] == 0){
                      covered_topic--;
                    }
                  }
                }
              }
            }
          }
        }
      }
      
    }
  }
}
