class Solution {
public:
    int rearrangeCharacters(string s, string target) {
         int hashS[27] = {0};
         int hashT[27] = {0};
         for(auto i:s)
        {
            hashS[i-'a']++;
        }

        for(auto i:target)
        {
            hashT[i-'a']++;
        }

        int count = INT_MAX;
        
        for(auto i:target)
        {
            count = min(count, hashS[i-'a']/hashT[i-'a']);
        }
        return count;
    }
};