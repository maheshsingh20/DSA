/*
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> pow2(n, 1);

        // Precompute powers of 2 modulo mod
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % mod;

        int start = 0, end = n - 1;
        int res = 0;

        while (start <= end) {
            if (nums[start] + nums[end] <= target) {
                res = (res + pow2[end - start]) % mod;
                start++;
            } else {
                end--;
            }
        }

        return res;
    }
};


*/


#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
  TrieNode* children[26];
  bool isTerminal;
  TrieNode(){
      for(int i=0;i<26;i++){
          children[i]=NULL;
      }
      isTerminal=false;
  }
};
class Trie{
  TrieNode* root;
  public:
  Trie(){
    root = new TrieNode();
  }
  void insert(string word){
    TrieNode *node = root;

    for(char ch:word){
      ch=tolower(ch);
      if(node->children[ch-'a']==nullptr){
        node->children[ch-'a']=new TrieNode();
      }
      node=node->children[ch-'a'];
    }
    node->isTerminal=true;
  }
  //search
  bool search(string word){
    TrieNode *node = root;

    for(char ch:word){
      ch=tolower(ch);
      if(node->children[ch-'a']==nullptr){
        return false;
      }else{
        node=node->children[ch-'a'];
      }
    }
    return node->isTerminal;
  }
  bool isPrefix(string word){
    TrieNode *node = root;
    for(char ch:word){
      ch = tolower(ch);
      if(node->children[ch-'a']==nullptr){
        return false;
      }
      node = node->children[ch-'a'];
    }
    return true;
  }
};





int main(){
  Trie tr;
  tr.insert("Mahesh");
  bool found=tr.isPrefix("Mahed");
  if(found){
    cout<<"Found"<<endl;
  }else{
    cout<<"Not Found"<<endl;
  }
  return 0;
}
