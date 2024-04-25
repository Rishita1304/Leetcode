class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto i:num){
            while(!s.empty() && k>0 && s.top()>i){
                s.pop();
                k--;
            }
            if(!s.empty() || i!='0') s.push(i);
        }
        while(!s.empty() && k){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans = "";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};