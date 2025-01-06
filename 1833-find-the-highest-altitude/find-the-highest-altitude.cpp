class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        int sum = 0;
        ans.push_back(sum);
        for(auto g:gain) {
            sum += g;
            ans.push_back(sum);
        } 
        int maxi = *max_element(ans.begin(), ans.end());
        return maxi;
    }
};