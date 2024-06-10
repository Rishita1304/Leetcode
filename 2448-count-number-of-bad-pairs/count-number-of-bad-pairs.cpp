class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> mp;
        long long cnt=0;
        long long n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]-i]++;
        for(auto i:mp) cnt+= ((i.second * (i.second-1))/2);
        long long total = (n*(n-1))/2;
        return total-cnt;
    }
};