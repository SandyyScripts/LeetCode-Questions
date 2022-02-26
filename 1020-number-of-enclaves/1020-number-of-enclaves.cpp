class Solution {
public:
    bool isValid(int n,int m,int i,int j,vector<vector<int>> &grid){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    int ans(vector<vector<int>> &grid){
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    grid[i][j]=0;
                }
                else if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
    void DFS(int n,int m,int i,int j,vector<vector<int>>& grid){
        grid[i][j]=2;
        if(isValid(n,m,i,j+1,grid)){
            DFS(n,m,i,j+1,grid);
        }
        if(isValid(n,m,i,j-1,grid)){
            DFS(n,m,i,j-1,grid);
        }
        if(isValid(n,m,i+1,j,grid)){
            DFS(n,m,i+1,j,grid);
        }
        if(isValid(n,m,i-1,j,grid)){
            DFS(n,m,i-1,j,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            int j=0;
            if(grid[i][j]==1){
                DFS(n,m,i,j,grid);
            }
            j=m-1;
            if(grid[i][j]==1){
                DFS(n,m,i,j,grid);
            }
        }
        for(int j=0;j<m;j++){
            int i=0;
            if(grid[i][j]==1){
                DFS(n,m,i,j,grid);
            }
            i=n-1;
            if(grid[i][j]==1){
                DFS(n,m,i,j,grid);
            }
        }
        int num=ans(grid);
        return num;
    }
};