class Solution {
public:
    int func(vector<int>& nums, int k){
        int odd = 0;
        int i=0;
        int j=0;
        int n = nums.size();
        int cnt = 0;

        while(j<n){
            if(nums[j]%2!=0) odd++;
            while(odd > k){
                if(nums[i]%2!=0) odd--;
                i++;
            }
            if(odd <= k) cnt+= (j-i+1);
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums, k-1);









        // unordered_map<int, int> mp;
        // mp[0] = 1; // for when prefix itself is a valid subarray
        // int cnt = 0, res = 0;

        // for (int num : nums) {
        //     if (num % 2 != 0) cnt++; // count odd numbers
        //     if (mp.find(cnt - k) != mp.end())
        //         res += mp[cnt - k];
        //     mp[cnt]++;
        // }
        // return res;
    }
};