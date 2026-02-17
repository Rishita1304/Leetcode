class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
            mini = min(mini, prices[i]);
            int sell = prices[i] - mini;
            ans = max(ans, sell);
        }
        return ans;
    }
};