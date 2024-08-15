
class Solution {
public:
    int solve(int i, int j, int n,vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i<0 || j<0 || j>=n) return 1e9;
        if(i==0) return mat[i][j];
        if(dp[i][j]!=-1e9) return dp[i][j];
        int upLeft = mat[i][j] + solve(i-1, j-1,n,mat,dp);
        int upAbove = mat[i][j] + solve(i-1, j,n,mat,dp);
        int upRight = mat[i][j] + solve(i-1, j+1,n,mat,dp);
        return dp[i][j] = min(upLeft, min(upAbove,upRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,-1e9));
        int mini = 1e9;
        for(int j=0;j<n;j++){
            mini = min(mini, solve(n-1,j,n,matrix,dp)) ;
        }
        return mini;
    }
};