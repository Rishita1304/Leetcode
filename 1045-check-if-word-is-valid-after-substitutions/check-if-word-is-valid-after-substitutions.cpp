class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='a') st.push(c);
            else if(c=='b') st.push(c);
            else if(c=='c' && st.size()>=2){
                char ch1 = st.top(); st.pop();
                char ch2 = st.top(); st.pop();
                if(ch1!='b' || ch2!='a'){
                    st.push(ch2);
                    st.push(ch1);
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};