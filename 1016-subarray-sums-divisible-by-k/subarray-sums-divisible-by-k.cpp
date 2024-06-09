class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        int i=0, cnt=0;
        int curr_sum=0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        while(i<n){
            curr_sum+=nums[i++];
            int rem=curr_sum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end())
                cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};