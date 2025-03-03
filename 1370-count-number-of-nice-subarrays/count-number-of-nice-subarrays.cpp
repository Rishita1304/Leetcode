class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, cnt = 0;
        for(int l=0, r=0; r<nums.size(); r++){
            if(nums[r]%2){
                k--;
                cnt=0;
            }
            while(k==0){
                cnt++;
                k += (nums[l]%2);
                l++;
            }
            res += cnt;
        }
        return res;
    }
};