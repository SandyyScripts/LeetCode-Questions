class Solution {
    
    bool isSafe(int row, int col, vector<string> board, int n){
        int dummyrow = row;
        int dummycol = col;
        
        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q') 
                return false;
            row--;
            col--;
        }
        
        row = dummyrow;
        col = dummycol;
        
        while(col >= 0){
            if(board[row][col] == 'Q') 
                return false;
            col--;
        }
        
        row = dummyrow;
        col = dummycol;
        
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    
    
public:
    
    //Solve using backtracking
    void solve(int col, vector<string> &board, vector<vector<string>> &res, int n){
        //if all queens are placed at right positions 
        if(col == n){
            res.push_back(board);
            return;
        }
        //for every row check where queen can be placed without getting killed
        for(int row=0; row<n; row++){
            //check wheather its safe or not place the queen in right place or not
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
    }
	
    //Driver Function
    vector<vector<string>> solveNQueens(int n) {
        //result matrix
        vector<vector<string>> res;
        //board vector for n 
        vector<string> board(n);
        //string with length n having all "."
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        //Solve for Backtracking
        solve(0,board,res,n);
        return res;
    }
};