class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> temp(h.begin(), h.end());
        sort(h.begin(), h.end());
        int cnt=0;
        int n = h.size();
        for(int i=0;i<n;i++){
            if(temp[i]!=h[i]) cnt++;
        }
        return cnt;
    }
};