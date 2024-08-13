class Solution {
public:
    void solve(vector<int>& cand, int target,int ind, vector<int> &temp, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<cand.size();i++){
            if(i>ind && cand[i]==cand[i-1] ) continue;
            if(cand[i]>target) break;
            temp.push_back(cand[i]);
            solve(cand, target-cand[i], i+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(cand.begin(), cand.end()); //1,1,2,5,6,7,10
        solve(cand, target, 0, temp, ans);
        return ans;
    }
};