class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto d:details) {
            int a = d[11] - '0';
            int b = d[12] - '0';
            int temp = a*10 + b;
            if(temp>60) cnt++;
        } 
        return cnt;
        
    }
};