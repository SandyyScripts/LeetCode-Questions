class Solution {
public:
    int calc(vector<vector<int>> &dp,vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mincost=INT_MAX;
        for(int k=0;k<moveCost[grid[i][j]].size();k++){
            mincost=min(mincost,grid[i][j]+moveCost[grid[i][j]][k]+calc(dp,grid,moveCost,i+1,k));
        }
        return dp[i][j]=mincost;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(52,vector<int>(52,-1));
        int minc=INT_MAX;
        for(int col=0;col<grid[0].size();col++){
            minc=min(minc,calc(dp,grid,moveCost,0,col));
        }
        return minc;
    }
};