class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && t[s.top()]<t[i]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};