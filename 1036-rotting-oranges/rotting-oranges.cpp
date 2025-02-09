class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //put rotten in queue
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                //count fresh
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            while(size--){

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0; i<4;i++){
                    int row = r+delr[i];
                    int col = c+delc[i];

                    //process the fresh oranges
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        flag = true;
                    }
                }
            }
            //if change happened in this traversal increase the time
            if(flag) time++;
        }

        //check if all fresh turned rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    time = -1;
                }
            }
        }
        return time;
    }
};