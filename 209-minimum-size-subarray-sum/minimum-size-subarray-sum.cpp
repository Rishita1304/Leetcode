class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int i=0;
        int j=0;
        int n = nums.size();
        int sum = 0;
        while(j<n){
            sum += nums[j];
            if(sum >= target){
                while(sum >= target && i<=j){
                    int len = j-i+1;
                    minLen = min(minLen, len);
                    sum -= nums[i];
                    i++;
                }
            }
            j++;
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};