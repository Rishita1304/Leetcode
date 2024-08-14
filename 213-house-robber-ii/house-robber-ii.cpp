class Solution {
public:
    int solve(int i, vector<int> nums, vector<int>& dp){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + solve(i-2,nums,dp);
        int not_take = solve(i-1, nums,dp);
        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> nums1, nums2,dp1(n,-1), dp2(n,-1);
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        return max(solve(n-2,nums1,dp1), solve(n-2, nums2, dp2));
    }
};