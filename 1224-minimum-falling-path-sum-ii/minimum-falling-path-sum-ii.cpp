class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(2, vector<int> (n,-1));
        for(int j=0;j<n;j++) dp[0][j] = grid[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i%2][j] = grid[i][j];
                int min_prev = INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j) min_prev = min(min_prev, dp[(i-1)%2][k]);
                }
                dp[i%2][j] += min_prev;
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans, dp[(n-1)%2][j]);
        }
        return ans;
    }
};