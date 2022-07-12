class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> prev(grid[0].size(),0);
        
        for(int i=0;i<grid.size();i++){
            vector<int> curr(grid[0].size(),0);
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int left=1e9;
                    int up = 1e9;
                    if(i>0) up=grid[i][j]+prev[j];
                    if(j>0) left=grid[i][j]+curr[j-1];
                    curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[grid[0].size()-1];
    }
    // int helper(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return 1e9;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up = grid[i][j]+helper(grid,i,j-1,dp);
    //     int left = grid[i][j]+helper(grid,i-1,j,dp);
    //     return dp[i][j]=min(up,left);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n,vector<int> (m,-1));
    //     return helper(grid,n-1,m-1,dp);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    //     for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid[0].size();j++){
    //             if(i==0 && j==0) dp[i][j]=grid[i][j];
    //             else{
    //                 int left=1e9;
    //                 int up = 1e9;
    //                 if(i>0) up=grid[i][j]+dp[i-1][j];
    //                 if(j>0) left=grid[i][j]+dp[i][j-1];
    //                 dp[i][j]=min(up,left);
    //             }
    //         }
    //     }
    //     return dp[grid.size()-1][grid[0].size()-1];
    // }
};