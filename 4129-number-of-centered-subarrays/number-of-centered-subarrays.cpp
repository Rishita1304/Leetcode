class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        set<int> st;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
             sum = 0;
             st.clear();
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                st.insert(nums[j]);
                if(st.contains(sum)) {
                    count++;
                }
            }        
        }
        return count;
    }
};