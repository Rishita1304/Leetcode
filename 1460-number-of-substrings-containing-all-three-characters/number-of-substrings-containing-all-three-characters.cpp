class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0,j=0,ans=0;
        vector<int> v(3,0);
        for(int j=0;j<n;j++){
            v[s[j]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0 && i<=j){
                v[s[i]-'a']--;
                ans+=(n-j);
                i++;
            }
        }
        return ans;
    }
};