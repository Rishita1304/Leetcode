class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rows(n,0);

        int m = grid[0].size();
        vector<int> columns(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    rows[i]++;
                    columns[j]++;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && ( columns[j]>1 || rows[i]>1 )){
                    ans++;
                }
            }
        }
        return ans;
    }
};