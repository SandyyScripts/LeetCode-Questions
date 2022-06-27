class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
        for(int i=0;i<9;i++){
            // Row Check
            if(board[row][i]==val){
                return false;
            }
            if(board[i][col]==val){
                return false;
            }
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == '.'){
                    for(char val='1';val<='9';val++){
                        if(isSafe(i,j,board,val)){
                            board[i][j]=val;
                            if(solve(board)){
                                return true;
                            }
                            //Backtracking
                            else{
                                board[i][j]='.';
                            }
                         }
                     }
                     return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};