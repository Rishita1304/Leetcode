class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int a=nums[i]+nums[j];
                if(target==a){
                    return {i,j};
                }
            }
        }
        return {};
    }
};