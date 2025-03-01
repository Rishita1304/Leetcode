class Solution {
public:
    int backtrack(int start, string s, unordered_set<string> st){
        if(start == s.size()) return 0;
        int maxSplit = 0;
        for(int end = start+1; end <= s.size(); end++){
            string substring = s.substr(start, end - start);
            if(st.find(substring) == st.end()){
                st.insert(substring);
                maxSplit = max(maxSplit, 1+backtrack(end, s, st));
                st.erase(substring);
            }
        }
        return maxSplit;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return backtrack(0, s, st);
    }
};