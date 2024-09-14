class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        int maxi=0;
        int len=0;
        for(int ele:nums){
            if(ele==x) maxi = max(maxi, ++len);
            else len=0;
        }
        return maxi;
    }
};