class Solution {
public:
    string largestEven(string s) {
        string res = s;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '1'){
                res = res.substr(0,res.size()-1);
            }
            else{
                break;
            }
        }
        return res;
    }
};