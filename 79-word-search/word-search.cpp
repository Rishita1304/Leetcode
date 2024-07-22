class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<int>> &vis, int n, int m, int i,int j, int ind){
        if(ind==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || word[ind]!=board[i][j]) return false;

        vis[i][j] = 1;

        bool left = dfs(board, word, vis,n,m, i,j-1,ind+1);
        bool right = dfs(board, word, vis,n,m, i,j+1,ind+1);
        bool up = dfs(board, word, vis,n,m, i+1,j,ind+1);
        bool down = dfs(board, word, vis,n,m, i-1,j,ind+1);

        vis[i][j] = 0;

        return left|right|up|down;
    };
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]==word[0])
                    if(dfs(board, word, vis,n,m, i,j,0)) 
                        return true;
            }
        }
        return false;
    }
};