class Solution {
public:
    int solve(int r,int precol, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(r==grid.size()) return 0;
        if(dp[r][precol]!=-1) return dp[r][precol];
        int ans = INT_MAX;
        for(int i=0;i<grid.size();i++){
            if(i!=precol) ans = min(ans, grid[r][i]+solve(r+1,i,grid,dp)); 
        }
        return dp[r][precol] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0,n,grid,dp);
    }
};