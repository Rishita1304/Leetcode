class Solution {
public:
    //same as 3rd part only difference is 
    //instead of 2, k transactions are allowed

    int solve(int ind, int buy, int n, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap] == -1){
            if(buy) dp[ind][buy][cap] = max( -prices[ind] + solve(ind+1, 0, n, cap, prices, dp), solve(ind+1, 1, n, cap, prices, dp));
            else dp[ind][buy][cap] = max( prices[ind] + solve(ind+1, 1, n, cap-1, prices, dp), solve(ind+1, 0, n, cap, prices, dp));
        } 
        return dp[ind][buy][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(0, 1, n, k, prices, dp);
    }
};