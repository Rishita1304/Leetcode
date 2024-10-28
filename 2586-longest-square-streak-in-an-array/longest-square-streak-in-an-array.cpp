class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int> mp;
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int num:nums){
            int s = sqrt(num);
            if(s*s == num && mp.find(s)!=mp.end()){
                mp[num] = mp[s] + 1;
                res = max(res, mp[num]);
            }
            else mp[num] = 1;
        }
        return res;
    }
};