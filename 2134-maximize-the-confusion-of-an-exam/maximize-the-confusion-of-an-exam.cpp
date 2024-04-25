class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        unordered_map<char,int> m;
        int l=0,r=0,n=a.size(),ans=-1,maxi=0;
        while(r<n){
            m[a[r]]++;
            maxi = max(maxi,m[a[r]]);
            int len = r-l+1;
            if(len-maxi>k){
                m[a[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
            r++;
        }
        return ans;
    }
};