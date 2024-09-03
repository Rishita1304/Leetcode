class Solution {
public:
    int getLucky(string s, int k) {
        string ans="";
        for(auto ch:s){
            ans+= to_string(ch-'a'+1);
        }
        while(k--){
            int temp=0;
            for(char ch:ans){
                temp+=ch-'0';
            }
            ans = to_string(temp);
        }
        return stoi(ans);
    }
};