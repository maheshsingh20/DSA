#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  TrieNode *children[26];
  bool isTerminal;
  TrieNode()
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }
  void insert(string word)
  {
    TrieNode *node = root;

    for (char ch : word)
    {
      ch = tolower(ch);
      if (node->children[ch - 'a'] == nullptr)
      {
        node->children[ch - 'a'] = new TrieNode();
      }
      node = node->children[ch - 'a'];
    }
    node->isTerminal = true;
  }
  // search
  bool search(string word)
  {
    TrieNode *node = root;

    for (char ch : word)
    {
      ch = tolower(ch);
      if (node->children[ch - 'a'] == nullptr)
      {
        return false;
      }
      else
      {
        node = node->children[ch - 'a'];
      }
    }
    return node->isTerminal;
  }
  bool isPrefix(string word)
  {
    TrieNode *node = root;
    for (char ch : word)
    {
      ch = tolower(ch);
      if (node->children[ch - 'a'] == nullptr)
      {
        return false;
      }
      node = node->children[ch - 'a'];
    }
    return true;
  }
};

int main()
{
  Trie tr;
  tr.insert("Mahesh");
  bool found = tr.isPrefix("Mahed");
  if (found)
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not Found" << endl;
  }
  return 0;
}

//Revise it again

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  bool isTerminal;
  TrieNode *child[26];

  TrieNode()
  {
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
    isTerminal = false;
  }
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  // Insert a word
  void insert(string word)
  {
    TrieNode *node = root;
    for (char ch : word)
    {
      ch = tolower(ch);
      if (node->child[ch - 'a'] == nullptr)
      {
        node->child[ch - 'a'] = new TrieNode();
      }
      node = node->child[ch - 'a'];
    }
    node->isTerminal = true;
  }

  // Search for a word
  bool isExist(string word)
  {
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      char ch = tolower(word[i]);
      if (node->child[ch - 'a'] == nullptr)
      {
        return false;
      }
      node = node->child[ch - 'a'];
    }
    return node->isTerminal;
  }

  /*Isprefix*/
  bool isPrefix(string_view str){
    int n = str.size();
    TrieNode *node = root;
    for (int i = 0; i < n;i++){
      char ch = tolower(str[i]);
      if(node->child[ch-'a']==nullptr){
        return false;
      }else{
        node = node->child[ch - 'a'];
      }
    }
    return true;
  }
};
int main()
{
  Trie tr;
  tr.insert("Mahesh");
  tr.insert("Anjali");
  tr.insert("Aniket");
  bool res = tr.isPrefix("Mahesh");
  bool res1 = tr.isPrefix("Ani");
  if (res1)
  {
    cout << "Exist" << endl;
  }
  else
  {
    cout << "Not Exist" << endl;
  }
  return 0;
}
