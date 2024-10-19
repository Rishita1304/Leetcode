class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n = s.size(), maxi = 0, i = 0, j = 0;
        while(i<n && j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j++]);
                maxi = max(maxi, j-i);
            }
            else st.erase(s[i++]);
        }
        return maxi;
    }
};