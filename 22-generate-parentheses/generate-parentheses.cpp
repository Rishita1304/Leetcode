class Solution {
public:
    void solve(int open, int close, int n, vector<string> &ans, string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n) solve(open+1, close, n, ans, s+"(");
        if(close<open) solve(open, close+1, n, ans, s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,ans,"");
        return ans;
    }
};