class Solution {
public:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        ans.push_back(output);  // Push the current subset

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // Skip duplicates

            output.push_back(nums[i]);
            solve(nums, output, i + 1, ans);  
            output.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        solve(nums, temp, 0, ans);
        return ans;
    }
};
