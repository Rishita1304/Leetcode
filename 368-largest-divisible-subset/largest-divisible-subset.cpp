class Solution {
public:
    vector<int> ans;
    void solve(int ind, vector<int>& temp, vector<int>& nums, vector<int>& dp){
        if(ind==nums.size()){
            //update main vector if temp has more elements
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
        //if temporary vector is empty, add current value to start subset building
        if(temp.size()==0){
            temp.push_back(nums[ind]);
            solve(ind+1,temp,nums,dp);
            temp.pop_back();
        }
        // if now the the temporary subset has potential to be largest and also divisible
        else if((int)temp.size()>dp[ind] && nums[ind]%temp.back()==0){
            dp[ind] = temp.size();
            temp.push_back(nums[ind]);
            solve(ind+1,temp,nums,dp);
            temp.pop_back();
        }
        solve(ind+1,temp,nums,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<int> dp(n+1, -1);
        sort(nums.begin(), nums.end());
        solve(0, temp, nums, dp);
        return ans;
    }
};