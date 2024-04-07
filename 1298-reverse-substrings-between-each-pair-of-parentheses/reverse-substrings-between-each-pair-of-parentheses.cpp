class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string ans = "";
        for(char c:s){
            if(c=='('){
                st.push(ans);
                ans = "";
            }
            else if(c==')'){
                reverse(ans.begin(), ans.end());
                string top = st.top(); st.pop();
                top+=ans;
                ans = top;
            }
            else ans+=c;
        }
        return ans;
    }
};