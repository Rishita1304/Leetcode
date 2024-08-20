class Solution {
public:
    int solve(int i, int t, vector<int> &coins,vector<vector<int>> &dp){
        if(i==0) return (t%coins[0]==0);
        if(dp[i][t]!=-1) return dp[i][t];

        int notpick = solve(i-1,t,coins,dp);
        int pick = 0; if(coins[i]<=t) pick = solve(i, t-coins[i],coins,dp);

        return dp[i][t] = pick+notpick;
    }
    int change(int k, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return solve(n-1,k,coins, dp);
    }
};