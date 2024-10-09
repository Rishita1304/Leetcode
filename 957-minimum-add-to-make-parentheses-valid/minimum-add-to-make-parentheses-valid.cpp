class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0) return 0;
        stack<char> st;
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]==')' ){
                if(st.empty()) c++;
                else if(st.top()=='('){
                    st.pop();
                }
                else st.push(s[i]);
            }
            else st.push('(');
        }
        return st.size() + c;
    }
};