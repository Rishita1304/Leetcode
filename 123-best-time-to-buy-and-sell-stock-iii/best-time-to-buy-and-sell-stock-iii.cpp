class Solution {
public:
    //since at most 2 transaction is possible,
    //cap value will start from 2,
    //and whenever sell is done cap will be reduced by 1

    int solve(int ind, int buy, int n, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy){ 
            int take = -prices[ind] + solve(ind+1, 0, n, cap, prices, dp);
            int notTake = 0 + solve(ind+1, 1, n, cap, prices, dp);
            return dp[ind][buy][cap] = max(take, notTake);
        }
        else{ 
            int take = prices[ind] + solve(ind+1, 1, n, cap-1, prices, dp);
            int notTake = 0 + solve(ind+1, 0, n, cap, prices, dp);
            return dp[ind][buy][cap] = max( take, notTake);
        } 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return solve(0, 1, n, 2, prices, dp);
    }
};