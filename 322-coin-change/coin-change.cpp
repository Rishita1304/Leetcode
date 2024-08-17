class Solution {
public:
    int solve(int i, int k, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0){
            if(k%coins[i]==0) return k/coins[i];
            else return 1e9;
        }
        if(dp[i][k]!=-1) return dp[i][k];

        int pick = 1e9; if(k>=coins[i]) pick = 1 + solve(i, k-coins[i], coins, dp);
        int notpick = solve(i-1,k,coins,dp);
        return dp[i][k] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        int ans = solve(n-1,k,coins,dp);
        return ans==1e9 ? -1 : ans;
    }
};