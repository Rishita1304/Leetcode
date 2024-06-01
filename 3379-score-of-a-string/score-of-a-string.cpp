class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.size();i++){
            int d = abs(s[i]-s[i-1]);
            sum+=d;
        }
        return sum;
    }
};