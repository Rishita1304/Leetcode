class Solution {
public:
    vector<string> ans;
    int n;
    bool isValid(string str){
        if(str[0]=='0') return false;
        int num = stoi(str);
        if(num>255) return false;
        return true;
    }
    void solve(string s, int i, int parts, string curr){
        if(i==n && parts==4){
            curr.pop_back();
            ans.push_back(curr);
        }
        if(i+1<=n) solve(s,i+1,parts+1, curr+s.substr(i,1)+".");
        if(i+2<=n && isValid(s.substr(i,2))){
            solve(s,i+2,parts+1, curr+s.substr(i,2)+".");
        }
        if(i+3<=n && isValid(s.substr(i,3))){
            solve(s,i+3,parts+1, curr+s.substr(i,3)+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if(n>12) return {};
        int parts=0;
        solve(s,0,parts,"");
        return ans;
    }
};