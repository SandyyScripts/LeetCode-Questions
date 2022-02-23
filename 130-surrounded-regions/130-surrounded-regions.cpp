class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>> &board){
        if(i>=0 && j>=0 && i<board.size() && j<board[0].size()-1 && board[i][j]=='O'){
            return true;
        }
        return false;
    }
    void convert(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='B'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
    void DFS(vector<vector<char>> &board,int i,int j){
        board[i][j]='B';
        if(isValid(i,j+1,board)){
            DFS(board,i,j+1);
        }
        if(isValid(i,j-1,board)){
            DFS(board,i,j-1);
        }
        if(isValid(i+1,j,board)){
            DFS(board,i+1,j);
        }
        if(isValid(i-1,j,board)){
            DFS(board,i-1,j);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            int j=0;
            if(board[i][j]=='O'){
                DFS(board,i,j);
            }
            j=m-1;
            if(board[i][j]=='O'){
                DFS(board,i,j);
            }
        }
        for(int j=0;j<m;j++){
            int i=0;
            if(board[i][j]=='O'){
                DFS(board,i,j);
            }
            i=n-1;
            if(board[i][j]=='O'){
                DFS(board,i,j);
            }
        }
        convert(board);
    }
};