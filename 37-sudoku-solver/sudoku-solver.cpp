class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)==true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board,int row,int col, int val){
        for(int i=0;i<9;i++){
            if(board[row][i]==val) return false;

            if(board[i][col]==val) return false;

            if(board[(3*(row/3)) + (i/3)][(3*(col/3)) + (i%3)] == val) return false;
        }
        return true;
    }
};