#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A'); // manual conversion to lowercase
        }
    }
    return s;
}
int main() {
    string sentence;
    getline(cin, sentence); // read full sentence including spaces
    string words[500];   // stores unique words
    int numoftimeoccur[500] = {0}; // stores count for each word
    int uniqcnt = 0; // number of unique words found
    string current = "";
    for (int i = 0; i <= sentence.length(); i++) {
        char ch = sentence[i];
        // If space or end of sentence reached
        if (ch == ' ' || i == sentence.length()) {
            if (current != "") {
                current = toLower(current); // make lowercase for comparison
                // Check if already present
                int foundIndex = -1;
                for (int j = 0; j < uniqcnt; j++) {
                    if (words[j] == current) {
                        foundIndex = j;
                        break;
                    }
                }
                // If found, increment count; else add as new word
                if (foundIndex != -1) {
                    numoftimeoccur[foundIndex]++;
                } else {
                    words[uniqcnt] = current;
                    numoftimeoccur[uniqcnt] = 1;
                    uniqcnt++;
                }
                current = ""; // reset for next word
            }
        } 
        else {
            current += ch; // build current wrd
        }
    }
    /*display number of time a word occur*/
    cout << "Number of time worrd occur:\n";
    for (int i = 0; i < uniqcnt; i++) {
        cout << words[i] << " : " << numoftimeoccur[i] << "\n";
    }
    return 0;
}