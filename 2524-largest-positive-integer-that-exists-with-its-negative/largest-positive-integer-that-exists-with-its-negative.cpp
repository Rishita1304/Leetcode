class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0, j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==0) return nums[j];
            else if(nums[i]+nums[j]<0) i++;
            else j--;
        }
        return -1;
    }
};