/*Brute Force-->Giving TLE*/
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }
        vis[i][j] = true;
        int ans = 1;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            int row = i + dir[k].first;
            int col = j + dir[k].second;
            ans += dfs(grid, row, col, vis);
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        for(int  i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    int res=dfs(grid,i,j,vis);
                    grid[i][j]=0;
                    ans=max(ans,res);
                }
            }
        }
        return ans==INT_MIN?n*m:ans;
    }
};


/*Optimal Solution   with O(n×m)+O(n×m)=O(n×m) */



class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& islandIndex, int index, int& size) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1 || islandIndex[i][j] != 0) {
            return;
        }
        islandIndex[i][j] = index;
        size++;
        dfs(grid, i + 1, j, islandIndex, index, size);
        dfs(grid, i - 1, j, islandIndex, index, size);
        dfs(grid, i, j + 1, islandIndex, index, size);
        dfs(grid, i, j - 1, islandIndex, index, size);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> islandIndex(n, vector<int>(m, 0));
        unordered_map<int, int> islandSize;
        int index = 1;
        int maxIslandSize = 0;

        // Assign each island a unique index and calculate its size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && islandIndex[i][j] == 0) {
                    int size = 0;
                    dfs(grid, i, j, islandIndex, index, size);
                    islandSize[index] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    index++;
                }
            }
        }

        // Check each 0 to see if changing it to 1 can merge islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    set<int> uniqueIslands;
                    int totalSize = 1; // Start with the current cell being changed to 1

                    // Check all four directions
                    if (i > 0 && grid[i-1][j] == 1) uniqueIslands.insert(islandIndex[i-1][j]);
                    if (i < n-1 && grid[i+1][j] == 1) uniqueIslands.insert(islandIndex[i+1][j]);
                    if (j > 0 && grid[i][j-1] == 1) uniqueIslands.insert(islandIndex[i][j-1]);
                    if (j < m-1 && grid[i][j+1] == 1) uniqueIslands.insert(islandIndex[i][j+1]);

                    // Sum the sizes of unique islands
                    for (int idx : uniqueIslands) {
                        totalSize += islandSize[idx];
                    }

                    maxIslandSize = max(maxIslandSize, totalSize);
                }
            }
        }

        return maxIslandSize;
    }
};

