#include <iostream>
#include <string>
using namespace std;

/*Function: longestrepchar Finds the length of the longest substring 
where we can replace at most k characters
to make all characters in the substring identical.
*/

int longestrepchar(string str, int k) {
    int freq[26] = {0};  // frequency of each character in current window
    int left = 0;        // window start index
    int maxfreq = 0;     // maximum frequency of any single character in the window
    int result = 0;
    for (int right = 0; right < str.length(); right++) {
        int index = str[right] - 'A';
        freq[index]++;
        // Update max frequency in current window
        if (freq[index] > maxfreq)
            maxfreq = freq[index];
        // If more than k replacements needed, shrink window from left
        while ((right - left + 1) - maxfreq > k) {
            freq[str[left] - 'A']--;
            left++;
        }
        // Update result with the size of the current valid window
        int windowSize = right - left + 1;
        if (windowSize > result)
            result = windowSize;
    }
    return result;
}
int main() {
    string str;
    int k;
    cin >> str >> k; 
    cout << longestrepchar(str, k) << endl;
    return 0;
}
