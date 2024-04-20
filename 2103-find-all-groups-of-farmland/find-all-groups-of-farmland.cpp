class Solution {
public:
    vector<int> dfs(vector<vector<int>>& land, unordered_set<string>& vis, int x, int y){
        stack<pair<int,int>> st;
        st.push({x,y});
        vis.insert(to_string(x)+","+to_string(y));

        int minrow = x, mincol = y;
        int maxrow = x, maxcol = y;

        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            int curX = cur.first, curY = cur.second;

            vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(auto d:dir){
                int nx = curX+d.first;
                int ny = curY+d.second;

                if(nx>=0 && nx<land.size() && ny>=0 && ny<land[0].size() &&land[nx][ny] == 1 && vis.find(to_string(nx)+","+to_string(ny)) == vis.end()){
                    vis.insert(to_string(nx)+","+to_string(ny));
                    st.push({nx,ny});
                    minrow = min(minrow,nx);
                    mincol = min(mincol,ny);
                    maxrow = max(maxrow,nx);
                    maxcol = max(maxcol,ny);
                }
            }
        }
        return {minrow,mincol,maxrow,maxcol};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        unordered_set<string> vis;
        vector<vector<int>> ans;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j] == 1 && vis.find(to_string(i)+","+to_string(j)) == vis.end()){
                    vector<int> temp = dfs(land, vis, i, j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};