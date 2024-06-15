class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i=0;i<n;i++){
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i=0;
        priority_queue<int> maxi;
        while(k--){
            while(i<n && projects[i].first<=w){
                maxi.push(projects[i].second);
                i++;
            }
            if(maxi.empty()) break;
            w+=maxi.top();
            maxi.pop();
        }
        return w;
    }
};