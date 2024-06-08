class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int pre=0;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            if(k!=0)
                pre = pre%k;
            if(mp.find(pre)!=mp.end()){
                if(i-mp[pre]>1) return true;
            }
            else mp[pre] = i;
        }
        return false;
    }
};