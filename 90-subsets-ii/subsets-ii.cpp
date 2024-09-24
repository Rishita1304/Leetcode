class Solution {
public:
    void solve(vector<int> nums,vector<int> output, int index,set<vector<int>>& ans){
        if(index>=nums.size()){
            ans.insert(output);
            return;
        }
        //take and call
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans); 

        //dont take and call
        output.pop_back();
        solve(nums, output, index+1, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, temp, 0, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};