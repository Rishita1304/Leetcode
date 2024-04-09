class Solution {
public:
    int clumsy(int n) {
        if(n<=0) return 0;
        int op = 0;
        stack<int> st;
        st.push(n);

        for(int i=n-1;i>=1;i--){
            if(op%4==0){
                int top = st.top();
                st.pop();
                st.push(top*i);
            }
            else if(op%4==1){
                int top = st.top();
                st.pop();
                st.push(top/i);
            }
            else if(op%4==2){
                st.push(i);
            }
            else if(op%4==3){
                st.push(-i);
            }
            op++;
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};