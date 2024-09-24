class Solution {
public:
     void solve(vector<vector<int>>& ans,vector<int> temp,int i,vector<int>& candidates,int &target,int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        } 
        if(i == candidates.size() || sum > target) return;

        temp.push_back(candidates[i]);
        sum += candidates[i];
        solve(ans,temp,i+1,candidates,target,sum);

        temp.pop_back();
        sum -= candidates[i];
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        solve(ans,temp,i+1,candidates,target,sum);

    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        sort(cand.begin(),cand.end());
        solve(ans,temp,0,cand,target,sum);
        return ans;

    }
};