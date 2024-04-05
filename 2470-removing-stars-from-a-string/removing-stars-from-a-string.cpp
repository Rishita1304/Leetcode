class Solution {
public:
    string removeStars(string s) {
        if(s.size()==0) return "";
        stack<char> st;
        for(char c:s){
            if(!st.empty() && c=='*') st.pop();
            else st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};