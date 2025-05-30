class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long acc = 0LL;
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            acc += nums[i];
            cnt += (2*acc >= sum);
        }
        return cnt;
    }
};