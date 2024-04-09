class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ind=0;
        for(auto c:s){
            if(c=='('){
                st.push(ind);
                ind=0;
            }
            else{
                ind = st.top() + max(ind*2, 1);
                st.pop();
            }
        }
        return ind;
    }
};