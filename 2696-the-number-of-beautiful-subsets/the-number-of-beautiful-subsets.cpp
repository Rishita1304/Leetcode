class Solution {
public:
    int ans=0;
    void solve(vector<int>& nums, int k, unordered_map<int,int>& mp, int i){
        if(i==nums.size()) ans++;
        else{
            if(!mp[nums[i]-k] && !mp[nums[i]+k])
            {
                mp[nums[i]]++;
                solve(nums,k,mp,i+1);
                mp[nums[i]]--;
            }
            solve(nums,k,mp,i+1);
        }

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        solve(nums, k, mp,0);
        return ans-1;
    }
};