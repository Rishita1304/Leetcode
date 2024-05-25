class Solution {
public:
    void solve(int i,string ans, string s, vector<string> &result, unordered_set<string> st){
        if(i>=s.size()){
            result.push_back(ans);
            return;
        }

        for(int j=i;j<s.size();j++){
            string word = s.substr(i,j-i+1);
            if(st.count(word)){
                string temp = ans;
                if(!ans.empty()){
                    ans+=" ";
                }
                ans+=word;
                solve(j+1, ans, s, result, st);
                ans = temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string ans = "";
        vector<string> result;
        unordered_set<string> st;
        for(auto w:wordDict){
            st.insert(w);
        }
        solve(0,ans,s,result,st);
        return result;
    }
};