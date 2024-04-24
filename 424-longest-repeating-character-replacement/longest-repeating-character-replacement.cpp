class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ans = -1, maxFreq = 0;
        int n = s.size();
        map<char, int> mp;
        while (j < n) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            int len = j-i+1;
            if (len - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j - i + 1));
            j++;
        }
        return ans;
    }
};