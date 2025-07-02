#include <bits/stdc++.h>
using namespace std;

/*

Find the Smallest Substring Containing All Characters of Another String
Sliding window + frequency map


string smallestSubstr(string str, string pat){
  int n=str.length();
  int m=pat.length();

  unordered_map<char,int> freq;
  for(auto it:pat){
    freq[it]++;
  }

  int count=0;
  int ans = INT_MAX;
  int start=0;
  string res;
  for (int i = 0; i < n;i++){
    if(freq.find(str[i])!=freq.end()){
      if(freq[str[i]]>0){
        count++;
      }
      freq[str[i]]--;
    }
    while(count==m){
      if(ans>i-start+1){
        ans=i-start+1;
        res=str.substr(start,ans);
      }
      if(freq.find(str[start])!=freq.end()){
        freq[str[start]]++;
        if(freq[str[start]]>0){
          count--;
        }
      }
      start++;
    }
  }
  return res;
}

int main(){
  string str = "ABADNCABDANDBC";
  string str1 = "ABBC";
  cout<<smallestSubstr(str,str1)<<endl;
  return 0;
}


*/


//Find the smallest substring of str that contains all characters of pat in the same order.



int main(){

}
