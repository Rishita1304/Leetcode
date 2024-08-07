class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> cells(n*n + 1, -1);

        // Fill the cells array with the board values

        bool leftToRight = true;
        int idx = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    cells[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    cells[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        // BFS to find the minimum number of moves
        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        
        q.push(1);  // start from cell 1
        visited[1] = true;
        int moves = 0;

         while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                
                if (curr == n * n) {
                    return moves;  // reached the last cell
                }
                for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                    int destination = (cells[next] == -1) ? next : cells[next];
                    if (!visited[destination]) {
                        visited[destination] = true;
                        q.push(destination);
                    }
                }
            }
            ++moves;
        }
        
        return -1;  // if not possible to reach the last cell
    }
};