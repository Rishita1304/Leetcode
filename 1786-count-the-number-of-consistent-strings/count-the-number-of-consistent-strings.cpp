class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_map<char,int>mp;
        for(auto i:allowed) mp[i]++;
        for(auto word:words){
            bool flag = true;
            for(auto ch:word){
                if(mp.find(ch)==mp.end()) flag=false;
            }
            if(flag) ans++;
        }
        return ans;
    }
};