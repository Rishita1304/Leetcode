class Solution {
public:
    int maxDepth(string s) {
        int a = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                a++;
            }
            else if(s[i]==')'){
                ans = max(ans,a);
                a--;
            }
        }
        return ans;
    }
};