#include <iostream>
#include <string>
#include <algorithm>

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    
    x--; 

    int left_walls = 0;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '#') {
            left_walls++;
        }
    }

    int right_walls = 0;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            right_walls++;
        }
    }

    int left_empty = 0;
    int right_empty = 0;
    int current_pos = x;
    while (current_pos > 0 && s[current_pos - 1] == '.') {
        left_empty++;
        current_pos--;
    }
    current_pos = x;
    while (current_pos < n - 1 && s[current_pos + 1] == '.') {
        right_empty++;
        current_pos++;
    }
    int segment_empty = 1; // Hamid's cell
    int L = x, R = x;
    while(L > 0 && s[L-1] == '.') L--;
    while(R < n-1 && s[R+1] == '.') R++;
    
    segment_empty = (R - L + 1) - (count(s.begin() + L, s.begin() + R + 1, '#'));

    std::cout << segment_empty << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}