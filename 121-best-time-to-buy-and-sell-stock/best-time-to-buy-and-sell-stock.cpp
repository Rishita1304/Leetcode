class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9;
        int maxi = 0;
        for(auto price:prices){
            mini = min(mini , price);
            int newMax = price - mini;
            maxi = max(maxi,newMax);
        }
        return maxi;
    }
};