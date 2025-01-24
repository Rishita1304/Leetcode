class Solution {
public:
    bool dfs(int s, vector<bool> &vis, vector<bool> &dfsvis,vector<vector<int>>& graph, vector<bool> &present){
        vis[s] = true;
        dfsvis[s] = true;

        for(auto x:graph[s]){
            if(!vis[x]){
                if(dfs(x, vis,dfsvis,graph,present)){
                    return present[s] = true;
                }
            }
            else if(vis[x] && dfsvis[x]){ 
                return present[s] = true;
            }
        }
        dfsvis[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<int> ans;
        
        int n = graph.size();

        vector<bool>vis(n, false); //visited
        vector<bool> dfsvis(n, false); //current path
        vector<bool> present(n, false); // cycle present
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, dfsvis,graph, present); //to check cycle is present
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> adjList(n);
//         vector<int> outdegree(n, 0);
//         queue<int> q;
//         vector<int> vis(n, 0);
//         for (int i = 0; i < n; i++) {
//             for (auto& g : graph[i]) {
//                 adjList[g].push_back(i);
//             }
//             outdegree[i] = graph[i].size();
//             if (outdegree[i] == 0)
//                 q.push(i);
//         }
//         while (!q.empty()) {
//             int front = q.front();
//             q.pop();
//             vis[front] = 1;
//             for (auto& a : adjList[front]) {
//                 outdegree[a]--;
//                 if (outdegree[a] == 0)
//                     q.push(a);
//             }
//         }
//         vector<int> ans;
//         for (int i = 0; i < n; i++) {
//             if (vis[i])
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };