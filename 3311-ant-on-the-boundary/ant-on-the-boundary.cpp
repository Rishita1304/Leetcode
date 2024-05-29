class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt=0;
        int ind = 0;
        for(auto n:nums){
            ind+=n;
            if(ind==0) cnt++;
        }
        return cnt;
    }
};