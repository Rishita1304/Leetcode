class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(auto i:nums2){
            while(!st.empty() && st.top()<i){
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nums1.size();i++)
            nums1[i] = mp.count(nums1[i]) ? mp[nums1[i]] : -1;
        
        return nums1;
    }
};