class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int oddcnt=0;
        for(auto i:s){
            mp[i]++;
            if(mp[i]%2==1)
                oddcnt++;
            else
                oddcnt--;
        }
        if(oddcnt>1)
            return s.size()-oddcnt+1;
        return s.size();

    }
};