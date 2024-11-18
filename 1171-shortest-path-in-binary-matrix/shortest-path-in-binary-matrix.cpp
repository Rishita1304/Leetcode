class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;

        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0,0}});

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            q.pop();

            if(row==n-1 && col==m-1) return dis;

            for(int k=0;k<8;k++){
                int nrow = row+drow[k];
                int ncol = col+dcol[k];

                if(isValid(nrow,ncol,n,m) && grid[nrow][ncol] == 0 && (dis + 1 < dist[nrow][ncol])){
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};