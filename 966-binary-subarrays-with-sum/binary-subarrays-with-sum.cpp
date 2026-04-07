class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int i = 0;
        int n = nums.size();
        int sum = 0;

        for(int j=0;j<n;j++){
            sum += nums[j];
            if(mp.find(sum-goal) != mp.end()){
                cnt += mp[sum-goal];
            }
            mp[sum]++;
        }

        return cnt;







        // unordered_map<int, int> mp;
        // int sum=0, count=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     if(sum==goal) count++;
        //     if(mp.find(sum - goal)!=mp.end()){
        //         count+=mp[sum-goal];
        //     }
        //     mp[sum]++;
        // }
        // return count;
    }
};