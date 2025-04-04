class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());  sort(s.begin(),s.end());
        int n=g.size(), m=s.size(), i=0, j=0, ans=0;

        while(i<n && j<m ){
            if(g[i] <= s[j]) {ans++; i++; j++;}
            else j++; 
        }
        return ans;
    }
};