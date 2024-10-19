class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0, i = 0, j = 0, len = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) zero++;
            while(zero>k){ //shrink the window
                if(nums[i]==0) zero--;
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};