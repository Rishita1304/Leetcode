class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, j=1;
        int n = nums.size();
        while(i<n && j<n){
            if(nums[i]==nums[j]){
                return true;
            }
            i++; j++;
        }
        return false;
    }
};