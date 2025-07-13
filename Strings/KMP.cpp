#include <bits/stdc++.h>
using namespace std;
vector<int> lpsFillFun(string pat)
{
  vector<int> lps(pat.size());
  int i = 1;
  int j = 0;
  int n = pat.length();

  while (i < n)
  {
    if (pat[i] == pat[j])
    {
      lps[i] = j + 1;
      i++;
      j++;
    }
    else
    {
      if (j != 0)
      {
        j = lps[j - 1]; // a wala jo concept hai jab pat[i]!=pat[j] to check kya krte hai  ki jo abtk ka longest prefic
        // aya hai uska longest common commfix match krega jo hao lps[j-1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

bool searchPattern(string pat, string txt){
  vector<int> lps = lpsFillFun(txt);
  int i = 0;
  int j = 0;
  int n = txt.length();
  int m = pat.length();
  while(i < n){
    if(pat[j]==txt[i]){
      i++;
      j++;
      if(j==m){
        return true;
      }
    }else{
      if(j!=0){
        j = lps[j-1];
      }else{
        i++;
      }
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s,t;
  cin>>s>>t;
  cout<<searchPattern(t,s)<<endl;
  return 0;
}
