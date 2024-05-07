class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0), count(26,0), ans;
        for(auto f:p) freq[f-'a']++;
        int i=0,j=0;
        int n = s.size(), m=p.size();
        if(m>n) return {};
        while(j<n){
            count[s[j]-'a']++;
            if((j-i+1)<m) j++;
            else if((j-i+1)==m){
                if(freq==count) ans.push_back(i);
                count[s[i]-'a']--;
                i++; j++;
            }
        }
        return ans;
    }
};