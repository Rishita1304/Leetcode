class Solution {
public:
    void backtrack(vector<int>& nums, int index, int currOR, int maxOR, int &count){
        if(currOR == maxOR) count++;
        for(int i=index; i<nums.size();i++){
            backtrack(nums, i+1, currOR | nums[i], maxOR, count);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, count = 0;  
        for(int num: nums) maxOR |= num;
        backtrack(nums,0,0,maxOR, count);
        return count;
    }
};