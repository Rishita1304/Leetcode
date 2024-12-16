class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        while(k--){
            int ind = 0, ans = nums[0];
            for(int i=1;i<n;i++){
                if(nums[i]<ans){
                    ans = nums[i];
                    ind = i;
                }
            }
            nums[ind] = nums[ind]*m;
        }
        return nums;
    }
};