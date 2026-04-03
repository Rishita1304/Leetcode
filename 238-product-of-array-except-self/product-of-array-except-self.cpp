class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixPro;
        int pro = 1;
        for(int n:nums){
            pro *= n;
            prefixPro.push_back(pro);
        }
        pro = 1;
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            if(i!=0){
                int p = prefixPro[i-1]*pro;
                ans.push_back(p);
                pro *= nums[i];
            }
            else{
                ans.push_back(pro);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};