class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc, int start_node, int end_node) {
        vector<pair<int, double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], suc[i]});
            adj[edges[i][1]].push_back({edges[i][0], suc[i]});
        }

        vector<double> dist(n, INT_MIN);
        dist[start_node] = 1;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto dis = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                double prob = it.second;
                
                if(dist[adjNode]< dis*prob){
                    dist[adjNode] = dis*prob;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return (dist[end_node]==INT_MIN) ? 0.00000 : dist[end_node];
    }
};