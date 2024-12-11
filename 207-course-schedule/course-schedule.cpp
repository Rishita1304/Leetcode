class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        vector<int> indegree(n);
        vector<int> ans;
        vector<vector<int>> adj(n);
        for(auto pre:p){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int front = q.front(); q.pop();
            ans.push_back(front);
            for(auto neighbor: adj[front]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
        return ans.size()==n;
    }
};