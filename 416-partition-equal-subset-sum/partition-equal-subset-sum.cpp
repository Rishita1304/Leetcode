class Solution {
public:
    bool solve(int i, int s, vector<int>& nums,vector<vector<int>>& dp){
        if(i<0) return false;
        if(s==0) return true;
        if(dp[i][s]!=-1) return dp[i][s];
        bool take; if(s>=nums[i]) take = solve(i-1, s-nums[i], nums, dp);
        bool not_take = solve(i-1, s, nums, dp);
        return dp[i][s] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return solve(n-1, sum/2, nums, dp);
    }
};