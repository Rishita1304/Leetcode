class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<=n;i++){
            int ind = lower_bound(begin(nums), end(nums), i) - begin(nums);
            int count =  n-ind;
            if(count==i) return count;
        }
        return -1;
    }
};