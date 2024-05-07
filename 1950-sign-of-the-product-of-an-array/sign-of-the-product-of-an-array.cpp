class Solution {
public:
    int arraySign(vector<int>& nums) {
        int c=0;
        for(auto n:nums){
            if(n==0) return 0;
            if(n<0) c++;
        }
        return c
        %2?-1:1;
    }
};