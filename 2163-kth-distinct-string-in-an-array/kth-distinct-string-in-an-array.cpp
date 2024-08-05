class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto a:arr) mp[a]++;
        for(auto a:arr){
            if(mp[a]==1){
                if(k==1) return a;
                k--;
            }
        }
        return "";
    }
};