class Solution {
public:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>>& grid, int x, int y, int islandId) {
        int n = grid.size();
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = islandId;
        int size = 1;
        for (auto [dx, dy] : directions) {
            size += dfs(grid, x + dx, y + dy, islandId);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandId = 2;
        unordered_map<int, int> islandSize;
        int maxSize = 0;

        // Step 1: Label each island with a unique ID and calculate its size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSize[islandId++] = size;
                    maxSize = max(maxSize, size);
                }
            }
        }

        // Step 2: Check each 0 cell to see the potential largest island it can create
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> visitedIslands;
                    int potentialSize = 1; // flip current 0 to 1
                    for (auto [dx, dy] : directions) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            int islandId = grid[x][y];
                            if (visitedIslands.find(islandId) == visitedIslands.end()) {
                                potentialSize += islandSize[islandId];
                                visitedIslands.insert(islandId);
                            }
                        }
                    }
                    maxSize = max(maxSize, potentialSize);
                }
            }
        }

        return maxSize;
    }
};