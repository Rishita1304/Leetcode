class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int s = (1<<n);
        for(int i=0;i<s;i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};