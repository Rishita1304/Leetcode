class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX;
        int max_profit = INT_MIN;
        for(int i:prices){
            m = min(i,m);
            int prof = i - m;
            max_profit = max(max_profit, prof);
        }
        return max_profit;
    }
};