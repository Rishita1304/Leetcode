class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int i=0;
        int j=0;
        int n = nums.size();
        int sum = 0;
        while(j<n){
            sum += nums[j++];
            while(sum >= target){
                minLen = min(minLen, j-i);
                sum -= nums[i++];
            }
        }
        return (minLen == INT_MAX)? 0: minLen;
    }
};