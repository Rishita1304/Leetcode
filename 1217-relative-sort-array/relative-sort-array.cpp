class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxi+1);
        for(auto i:arr1){
            count[i]++;
        }
        vector<int> ans;
        for(auto j:arr2){
            while(count[j]>0){
                ans.push_back(j);
                count[j]--;
            }
        }
        for(int i=0;i<=maxi;i++){
            while(count[i]>0){
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};