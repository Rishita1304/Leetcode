class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int c=0;
        int n=nums.size();
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int res = sum-k;
            if(mp.find(res)!=mp.end()){
                c+=mp[res];
            }
            mp[sum]++;
        }
        return c;
    }
};