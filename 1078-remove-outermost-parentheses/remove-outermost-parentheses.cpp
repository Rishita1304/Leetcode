class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int sum = 0;
        for(char i: s){
            //sum>0 means not at outer parathesis
            if(i == '(' && sum++ > 0) res += i;
            //sum>1 means not closing outermost layer
            if(i == ')' && sum-- > 1) res += i;
        }
        return res;
    }
};