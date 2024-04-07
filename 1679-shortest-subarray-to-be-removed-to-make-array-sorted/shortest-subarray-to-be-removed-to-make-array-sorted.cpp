class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int n=arr.size();
        while(i<j && arr[i]<=arr[i+1]) i++;
        if(i+1==n) return 0;
        while(j>i && arr[j]>=arr[j-1]) j--;

        int l=0;
        int r=j;
        int ans = min(n-i-1, j);
        while(l<=i && r<n){
            if(arr[l]<=arr[r]){
                ans = min(ans, r-l-1);
                l++;
            }
            else r++;
        }
        return ans;
    }
};