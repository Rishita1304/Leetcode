class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0, n=nums.size();
        int cnt=1;
        for(int j = 0;j<n;j++){
            if(j>0 && nums[j-1]+1 == nums[j]){
                cnt++;
            }
            if(j-i+1>k){
                if(nums[i]+1 == nums[i+1]){
                    cnt--;
                }
                i++;
            }
            if(j-i+1==k){
                ans.push_back(cnt==k ? nums[j] : -1);
            }
        }
        return ans;
    }
};