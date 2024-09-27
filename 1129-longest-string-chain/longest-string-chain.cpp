class Solution {
public:
    bool canFormChain(const string& curr, const string& prev) {
        if(curr.size() != prev.size() + 1) return false;
        int i = 0, j = 0;
        while(i < curr.size() && j < prev.size()) {
            if(curr[i] == prev[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        return j == prev.size();  // To ensure only one mismatch was allowed
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1);
        int maxLength = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(canFormChain(words[i], words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};
