class DisjointSet{
	public:
	vector<int> rank, parent, size;
	DisjointSet(int n){
		rank.resize(n+1, 0);
		size.resize(n+1, 1);
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
		}
	}
	int findUPar(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node] = findUPar(parent[node]);
	}
	void unionByRank(int u, int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(ulp_u==ulp_v) return;
		if(rank[ulp_u]< rank[ulp_v]) parent[ulp_u] = ulp_v;
		else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
	void unionBySize(int u, int v){
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(ulp_u==ulp_v) return;
		if(size[ulp_u]< size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        unordered_map<int,int> uniqueNode;
        DisjointSet ds(maxRow + maxCol + 1);
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionByRank(nodeRow, nodeCol);
            uniqueNode[nodeRow] = 1;
            uniqueNode[nodeCol] = 1;
        }
        int ans = 0;
        for(auto it:uniqueNode){
            if(ds.findUPar(it.first) == it.first) ans++;
        }
        return n-ans;
    }
};