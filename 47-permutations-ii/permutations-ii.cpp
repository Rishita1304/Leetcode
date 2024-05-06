class Solution {
public:
    void solve(int n, int ind, vector<int> nums, vector<vector<int>>& output){
        if(ind==n-1){
            output.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            if(ind!=i && nums[ind]==nums[i]) continue;
            swap(nums[ind],nums[i]);
            solve(n,ind+1,nums,output);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        solve(nums.size(), 0,nums,output);
        return output;
    }
};