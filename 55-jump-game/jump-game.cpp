class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        for(int i=j;i>=0;i--){
            if(i+nums[i]>=j) j=i;
        } 

        return j==0;
    }
};