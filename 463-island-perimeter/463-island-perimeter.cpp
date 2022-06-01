class Solution {
public:
    bool check(int i,int j,vector<vector<int>> &grid){
        if(i>=0 && j>=0 && i<=grid.size()-1 && j<=grid[0].size()-1){
            if(grid[i][j]==1){
                return true;
            }
        }
        return false;
    }
    int peri(vector<vector<int>> &grid,int i,int j){
        int total=4;
        if(check(i-1,j,grid)){
            total=total-1;
        }
        if(check(i,j-1,grid)){
            total=total-1;
        }
        if(check(i+1,j,grid)){
            total=total-1;
        }
        if(check(i,j+1,grid)){
            total=total-1;
        }
        return total;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=ans+peri(grid,i,j);
                }
            }
        }
        return ans;
    }
};