class Solution {
public:
    int largestCombination(vector<int>& can) {
        int n = can.size(), ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(auto c:can){
                if(c & (1<<i)) cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};