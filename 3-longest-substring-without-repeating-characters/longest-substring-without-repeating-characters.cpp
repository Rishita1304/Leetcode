class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i = 0,maxi = 0;
        for (int j = 0; j < s.size(); j++){
            while (st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};