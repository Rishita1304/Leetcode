class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return (a.second==b.second) ? (a.first > b.first) : a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size()==1) return nums;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> val;
        for(auto m:mp){
            val.push_back(m);
        }
        sort(val.begin(), val.end(), cmp);
        vector<int> res;
        for(auto v:val){
            for(int i=0;i<v.second;i++){
                res.push_back(v.first);
            }
        }
        return res;
    }
};