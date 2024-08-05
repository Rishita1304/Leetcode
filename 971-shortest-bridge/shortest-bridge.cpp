class Solution {
public:

    queue<pair<int, int>> q;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int x, int y, int n, vector<vector<int>>& grid) {
            if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) {
                return;
            }
            grid[x][y] = 2; // Mark the cell as part of the first island
            q.push({x, y});
            for (auto& dir : directions) {
                dfs(x + dir[0], y + dir[1], n, grid);
            }
        };
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool found = false;

        // Find the first island and mark it
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j,n,grid);
                    found = true;
                }
            }
        }

        // BFS to find the shortest bridge
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                
                for (auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1) {
                            return steps;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};