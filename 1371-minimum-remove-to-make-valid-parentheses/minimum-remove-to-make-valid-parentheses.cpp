class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0;
        int r = 0;
        stack<char> st;

        for(char c:s){
            if(c=='(') l++;
            else if(c==')') r++;
            if(r>l){
                r--; continue;
            }
            else st.push(c);
        }

        string ans = "";
        while(!st.empty()){
            char ch = st.top(); st.pop();
            if(l>r && ch=='(') l--;
            else ans+=ch;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};