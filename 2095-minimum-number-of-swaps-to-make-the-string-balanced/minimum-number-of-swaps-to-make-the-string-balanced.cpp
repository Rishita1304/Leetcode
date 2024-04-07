class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='[') st.push(c);
            if(c==']' && !st.empty() && st.top()=='[') st.pop();
        }
        int ans = st.size();
        if(ans%2==0) return ans/2;
        else return (ans+1)/2;
    }
};