class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1;i<=n;i++){
            //just half the i and add1 if last bit is 1
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};