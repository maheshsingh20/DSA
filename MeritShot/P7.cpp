#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + ('a' - 'A');
    }
    return s;
} /*convert all cases to lower case for cinsistency in case sensitivity */

int main() {
    string T, S;
    getline(cin, T); // Text
    getline(cin, S); // Characters to find
    // Convert both strings to lowercase
    T = toLower(T);
    S = toLower(S);
    // Arrays to store required character counts
    int need[256] = {0}; // characters required
    int have[256] = {0}; // characters we currently have in the window
    int requiredUnique = 0;
    // Fill 'need' array
    for (char c : S) {
        if (need[(unsigned char)c] == 0)
            requiredUnique++;
        need[(unsigned char)c]++;
    }
    // Sliding window variables
    int formed = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int startIndex = -1;
    while (right < T.length()) {
        char rc = T[right];
        have[(unsigned char)rc]++;
        // If character matches the required count
        if (need[(unsigned char)rc] > 0 &&
            have[(unsigned char)rc] == need[(unsigned char)rc]) {
            formed++;
        }
        /*try shrinking from left if all char match*/
        while (formed == requiredUnique && left <= right) {
            int windowLen = right - left + 1;
            if (windowLen < minLen) {
                minLen = windowLen;
                startIndex = left;
            }
            char lc = T[left];
            have[(unsigned char)lc]--;
            if (need[(unsigned char)lc] > 0 &&
                have[(unsigned char)lc] < need[(unsigned char)lc]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    if (startIndex == -1) {
        cout << "No valid window found" << endl;
    } else {
        for (int i = startIndex; i < startIndex + minLen; i++) {
            cout << T[i];
        }
        cout << endl;
    }
    return 0;
}
