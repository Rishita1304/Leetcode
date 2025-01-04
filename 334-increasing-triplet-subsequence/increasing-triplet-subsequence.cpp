class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        int one = INT_MAX, two = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>two) return true;
            else if(nums[i]>one) two = nums[i];
            else one = nums[i];
         }
         return false;
    }
};