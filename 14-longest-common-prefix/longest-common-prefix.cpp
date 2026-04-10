class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) { //not at the start or both doesn't get same
                prefix = prefix.substr(0, prefix.size() - 1); //trim 1 char from last
                // if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};