class Solution {
public:
    int res=0,empty=1;
    void dfs(vector<vector<int>>& grid,int x,int y,int count){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == -1) return;
        if(grid[x][y]==2){
            if(empty==count) res++;
            return;
        }
        grid[x][y]=-1;
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);   
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int s_i=0,s_j=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) s_i=i,s_j=j;
                else if(grid[i][j]==0) empty++;
            }
        }
        dfs(grid,s_i,s_j,0);
        return res;
    }
};