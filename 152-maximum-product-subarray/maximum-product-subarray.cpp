class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = 1;
        int minpro = 1;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) swap(maxpro, minpro);
            minpro = min(minpro*nums[i], nums[i]);
            maxpro = max(maxpro*nums[i], nums[i]);
            maxi = max(maxi, maxpro);
        }
        return maxi;
    }
};