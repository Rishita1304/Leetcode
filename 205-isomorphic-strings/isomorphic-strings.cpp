class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1, m2;
        int i=0,j=0,s1=s.size(), t1=t.size();
        if(s1!=t1) return false;
        while(i<s1 && j<t1){
            if(!m1.count(s[i]) && !m2.count(t[j])){
                m1[s[i]] = t[j];
                m2[t[j]] = s[i];
            }
            else if(m1[s[i]]!=t[j] || m2[t[j]]!=s[i]) return false;
            i++; j++;
        }
        return true;
        
    }
};