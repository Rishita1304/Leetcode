class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto i:t){
            mp[i]++;
        }
        int cnt = t.size();
        int i = 0;
        int minlen = INT_MAX;
        int start = -1;
        for(int j=0;j<s.size();j++){
            if(mp[s[j]] > 0) cnt--;
            mp[s[j]]--;

            while(cnt == 0){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt++;
                i++;
            }
        }
        if(start == -1) return "";
        return s.substr(start, minlen);




        // unordered_map<char,int> m1;
        // for(auto i:t) m1[i]++;

        // string ans;
        // int i = 0, j = 0, n = s.size();
        // int k = m1.size(), cnt = 0;
        // int minLen = 1e9, sIndex = -1;
        
        // while(j<n){
        //     if(m1.find(s[j])!=m1.end()){//found
        //         m1[s[j]]--;
        //         if(m1[s[j]]==0) cnt++;
        //     }
        //     while(cnt==k){
        //         if(j-i+1 < minLen){
        //             sIndex = i;
        //             minLen = min(minLen, j-i+1);
        //         }
        //         if(m1.find(s[i])!=m1.end()){
        //             if(m1[s[i]]==0) cnt--;
        //             m1[s[i]]++;
        //         }
        //         i++;
        //     }
        //     j++;
        // }
        // return sIndex==-1 ? "" : s.substr(sIndex, minLen);
    }
};