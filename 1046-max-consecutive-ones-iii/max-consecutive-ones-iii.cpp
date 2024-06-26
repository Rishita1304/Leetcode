class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0, i=0,j=0, ans=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) zero++;
            while(zero>k){
                if(nums[i]==0) zero--;
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};