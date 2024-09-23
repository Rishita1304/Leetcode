class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0); // dp[i] stores the min extra characters for s[i:]

        // DP approach to compute minimum extra characters
        for (int i = n - 1; i >= 0; --i) {
            // Initially assume we keep the current character, so 1 extra character
            dp[i] = dp[i + 1] + 1;

            // Check if any word in the dictionary matches a prefix starting from i
            for (int len = 1; len <= n - i; ++len) {
                string substr = s.substr(i, len);
                if (dict.count(substr)) {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};