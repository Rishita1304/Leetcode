class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i, co=0, s=0, ans=0;
        for(int i=0;i<arr.size();i++){
            s+=i;
            co+=arr[i];
            if(s==co) ans++;
        }
        return ans;
    }
};