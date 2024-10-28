class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp= {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n=s.size(), ans=0;

        for(int i=0;i<n;i++){

            if(mp[s[i]]<mp[s[i+1]]) ans = ans-mp[s[i]]; //XL -> 40 , L-X = 50-10
            
            else  ans = ans+mp[s[i]]; //LVIII = 50+5+3
            
        }
        return ans;
    }
};