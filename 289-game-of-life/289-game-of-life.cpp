class Solution {
public:
    int check(vector<vector<int>>& board,int i,int j,int n,int m){
        int val=0;
        if(i>0 && board[i-1][j]==1){
            val++;
        }
        if(j>0 && board[i][j-1]==1){
            val++;
        }
        if(i<n-1 && board[i+1][j]==1){
            val++;
        }
        if(j<m-1 && board[i][j+1]==1){
            val++;
        }
        if((i>0 && j>0) && board[i-1][j-1]==1){
            val++;
        }
        if((i<n-1 && j<m-1) && board[i+1][j+1]==1){
            val++;
        }
        if((i>0 && j<m-1) && board[i-1][j+1]==1){
            val++;
        }
        if((i<n-1 && j>0) && board[i+1][j-1]==1){
            val++;
        }
        return val;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> ans=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=check(ans,i,j,n,m);
                if(ans[i][j]==0){
                    if(val==3){
                        board[i][j]=1;
                    }
                }
                else{
                    if(val<2 || val>3){
                        board[i][j]=0;
                    }
                }
            }
        }
    }
};