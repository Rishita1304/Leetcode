class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s1(26,0);
        vector<int> t1(26,0);
        for(auto ch:s){
            s1[ch-'a']++;
        }
        for(auto ch:t){
            t1[ch-'a']++;
        }
        int steps=0;
        for(int i=0;i<26;i++){
            steps+=abs(s1[i]-t1[i]);
        }
        return steps/2;
    }
};