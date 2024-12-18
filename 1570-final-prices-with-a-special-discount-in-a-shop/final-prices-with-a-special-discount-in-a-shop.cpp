class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> discount(n, 0);
        for (int i{n-1}; i>=0; i--) {
            if (!s.empty())
                if (s.top() <= prices[i])
                    discount[i] = s.top();
                else {
                    while (!s.empty() && (s.top() > prices[i])) s.pop();
                    if (!s.empty()) discount[i] = s.top();
                }
            s.push(prices[i]);
        }
        vector<int> selling_price(n);
        for (int i{0}; i<n; i++)
            selling_price[i] = prices[i] - discount[i];
        return selling_price;
    }
};