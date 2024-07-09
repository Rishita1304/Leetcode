class Solution {
public:
    bool solve(string word, int l, int r){
        if(l>=r) return true;
        if(word[l]!=word[r]) return false;
        return solve(word,l+1, r-1);
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            int n = i.size();
            if(solve(i,0,n-1)) return i;
        }
        return "";
    }
};