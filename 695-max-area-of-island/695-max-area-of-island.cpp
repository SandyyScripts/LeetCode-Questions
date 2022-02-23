class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>> &grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1){
            return true;
        }
        return false;
    }
    void DFS(vector<vector<int>> &grid,int i,int j,int &ans){
       ans++;
       grid[i][j]=0;
       if(isValid(i,j+1,grid)){
           DFS(grid,i,j+1,ans);
       }
        if(isValid(i,j-1,grid)){
           DFS(grid,i,j-1,ans);
       }
        if(isValid(i+1,j,grid)){
           DFS(grid,i+1,j,ans);
       }
        if(isValid(i-1,j,grid)){
           DFS(grid,i-1,j,ans);
       }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(grid[i][j]==1){
                    int ans=0;
                    DFS(grid,i,j,ans);
                    count=max(count,ans);
                }
            }
        }
        return count;
    }
};