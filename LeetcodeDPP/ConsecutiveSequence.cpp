#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, pair<int, int>> dp; // Stores {sequence length, last index}
    int max_len = 0;
    int best_val = -1;
    
    for (int i = 0; i < n; i++) {
        int current = arr[i];
        int prev = current - 1;
        
        int current_len = 1;
        int last_idx = i + 1; // 1-based indexing
        
        if (dp.count(prev)) {
            current_len = dp[prev].first + 1;
        }
        
        // Only keep the rightmost occurrence
        if (dp.count(current)) {
            if (current_len > dp[current].first) {
                dp[current] = {current_len, last_idx};
            }
        } else {
            dp[current] = {current_len, last_idx};
        }
        
        if (current_len > max_len) {
            max_len = current_len;
            best_val = current;
        }
    }
    
    // Reconstruct the sequence
    vector<int> sequence;
    int current_val = best_val;
    int remaining = max_len;
    
    for (int i = n - 1; i >= 0 && remaining > 0; i--) {
        if (arr[i] == current_val) {
            sequence.push_back(i + 1);
            current_val--;
            remaining--;
        }
    }
    
    reverse(sequence.begin(), sequence.end());
    
    cout << max_len << "\n";
    for (int idx : sequence) {
        cout << idx << " ";
    }
    cout << "\n";
    
    return 0;
}