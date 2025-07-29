#include <bits/stdc++.h>
using namespace std;

bool dfs(int row, int col, bool free, vector<string>& grid, vector<vector<bool>>& visited){
    int n = grid[0].size();
    if(row == 1 && col == n - 1) return true;
    if(visited[row][col]) return false;
    
    visited[row][col] = true;

    if(free){
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (auto [dr, dc] : dir){
            int nRow = row + dr;
            int nCol = col + dc;
            if(nRow >= 0 && nRow < 2 && nCol >= 0 && nCol < n){
                if(dfs(nRow, nCol, false, grid, visited)) return true;
            }
        }
    } else {
        // Arrow move only
        if(grid[row][col] == '<'){
            int next = col - 1;
            if(next >= 0){
                if(dfs(row, next, true, grid, visited)) return true;
            }
        }
        else if(grid[row][col] == '>'){
            int next = col + 1;
            if(next < n){
                if(dfs(row, next, true, grid, visited)) return true;
            }
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];

        vector<vector<bool>> visited(2, vector<bool>(n, false));
        if(dfs(0, 0, true, grid, visited)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
