#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal; // Fixed typo: was isTerminal

    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    ~Trie()
    {
        clear(root);
    }

    void clear(TrieNode *node)
    {
        if (!node)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
            {
                clear(node->children[i]);
            }
        }
        delete node;
    }

    void insertUtil(TrieNode *node, const string &word, int index)
    {
        if (index == word.length())
        {
            node->isTerminal = true;
            return;
        }

        int childIndex = toupper(word[index]) - 'A';
        if (childIndex < 0 || childIndex >= 26)
            return; // Invalid character

        if (!node->children[childIndex])
        {
            node->children[childIndex] = new TrieNode(word[index]);
        }
        insertUtil(node->children[childIndex], word, index + 1);
    }

    void insertWord(const string &word)
    {
        if (word.empty())
            return;
        insertUtil(root, word, 0);
    }
    /*
    We traverse in trie so that if we find our next char we go further 
    int last we find our final node 
    if that node is terminal then we found our word otherwise return false
    
    */
    bool searchUtil(TrieNode *node, const string &word, int index)
    {
        if (index == word.length())
        {
            return node->isTerminal;
        }

        int childIndex = toupper(word[index]) - 'A';
        if (childIndex < 0 || childIndex >= 26)
            return false;

        if (!node->children[childIndex])
        {
            return false;
        }
        return searchUtil(node->children[childIndex], word, index + 1);
    }

    bool searchWord(const string &word)
    {
        if (word.empty())
            return false;
        return searchUtil(root, word, 0);
    }
    /*

    For deleting current node first of all we search the key and mark last node as false
    then we check if the node has any child then we don't delete it otherwise we delete it
    
    */
    void remove(TrieNode *root, string word)
    {
        if (!root)
            return;

        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        if (index < 0 || index > 25)
            return;

        TrieNode *child = root->children[index];
        remove(child, word.substr(1));

        // After returning, check if child is deletable
        if (child && child->isTerminal == false)
        {
            bool hasChild = false;
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != nullptr)
                {
                    hasChild = true;
                    break;
                }
            }
            if (!hasChild)
            {
                delete child;
                root->children[index] = nullptr;
            }
        }
    }

    void removeWord(string word)
    {
        remove(root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("ABCD");
    t.insertWord("ABCE");
    t.insertWord("ABCF");
    t.insertWord("ABCG");

    cout << "Search 'ABCD': " << (t.searchWord("ABCD") ? "Found" : "Not Found") << endl;
    cout << "Search 'XYZ': " << (t.searchWord("XYZ") ? "Found" : "Not Found") << endl;
    t.removeWord("ABCD");
    cout << "Search 'ABCD' after removal: " << (t.searchWord("ABCD") ? "Found" : "Not Found") << endl;
    return 0;
}