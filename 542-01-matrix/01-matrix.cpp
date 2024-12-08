class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dis(n, vector<int> (m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dRow[4] = {-1,0,1,0};
        int dCol[4] = {0,-1,0,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r = x+dRow[i];
                int c = y+dCol[i];
                if(r>=0 && c>=0 && r<n && c<m && mat[r][c]==1 && dis[r][c]==-1){
                    dis[r][c] = dis[x][y]+1;
                    q.push({r,c});
                }
            }
        }
        return dis;
    }
};