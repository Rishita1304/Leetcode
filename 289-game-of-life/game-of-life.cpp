class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& board){
        return (i>=0 && i<board.size() && j>=0 && j<board[0].size());
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = { 0, 0, 1, 1, 1,-1,-1,-1};
        vector<int> dy = {-1, 1, 0,-1, 1, 1,-1, 0};

        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                int count=0;
                for(int i=0;i<8;i++){
                    int r = row+dx[i], c = col+dy[i];
                    if(isValid(r,c,board) && abs(board[r][c])==1) count++;
                }
                if(board[row][col]==1 && (count<2 || count>3)) board[row][col]=-1;
                if(board[row][col]==0 && count==3) board[row][col]=2;
            }
        }
        for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]>=1) board[i][j]=1;
                    else board[i][j]=0;
                }
            }
    }
};