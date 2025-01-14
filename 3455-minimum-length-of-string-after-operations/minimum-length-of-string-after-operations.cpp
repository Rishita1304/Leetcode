class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> count;
        int sum=0;
        for(auto i:s){
            count[i]++;
            if(count[i]==3) count[i]-=2;
        }
        for(auto c:count){
            sum+=c.second;
        }
        return sum;
    }
};