class Solution {
public:
    bool check(vector<int>& nums) {
        //count the no. of decreasing times
        //if more than one ... not sorted
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]) count++;
        }
        return (count<=1);
    }
};