class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int max_profit = 0;
        for(int i:prices){
            buy = min(i,buy);
            int prof = i - buy;
            max_profit = max(max_profit, prof);
        }
        return max_profit;
    }
};