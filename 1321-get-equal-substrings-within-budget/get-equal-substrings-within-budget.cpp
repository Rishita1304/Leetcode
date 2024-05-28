class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int total=0;
        int maxLen=0;
        int n = s.size();
        while(j<n){
            total += abs(s[j]-t[j]);
            while(total>maxCost){
                total-=abs(s[i]-t[i]);
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};