class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size());
        vector<int> ans(nums.size());
        int pro = 1;
        for(int i=0;i<nums.size();i++){
            pro = pro*nums[i];
            product[i] = pro;
        }
        pro = 1;
        for(int i=nums.size()-1;i>=0;i--){
            int val = 0;
            if(i>0) val = pro*product[i-1];
            else val = pro;
            ans[i] = val;
            pro = pro*nums[i];
         }
         return ans;
    }
};