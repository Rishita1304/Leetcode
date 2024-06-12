class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum=0, ps=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(auto i:nums){
            sum+=i;
        }
        int rem = sum%p;
        if(rem==0) return 0;
        int ans=nums.size();
        for(int i=0;i<nums.size();i++){
            ps+=nums[i];
            if(ps-rem>=0 && mp.find((ps-rem)%p)!=mp.end()){
                ans=min(ans, i-mp[(ps-rem)%p]);
            }
            mp[ps%p] = i;
        }
        return (ans==nums.size()?-1:ans);
    }
};