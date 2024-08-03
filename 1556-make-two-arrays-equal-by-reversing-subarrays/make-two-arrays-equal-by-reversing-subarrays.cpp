class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001), cnt2(1001);
        for(auto v:target){
            ++cnt1[v];
        }
        for(auto v:arr){
            ++cnt2[v];
        }
        return cnt1==cnt2;
    }
};