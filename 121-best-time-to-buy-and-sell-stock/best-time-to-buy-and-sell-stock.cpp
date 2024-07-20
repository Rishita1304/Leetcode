class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int mx = 0;
        for(auto p:prices){
            mn = min(mn,p);
            int newnx = p-mn;
            mx = max(mx,newnx);
        }
        return mx;
    }
};