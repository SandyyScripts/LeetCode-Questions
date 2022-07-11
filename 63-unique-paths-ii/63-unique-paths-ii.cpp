class Solution {
public:
    // int mod = int(1e9+7);
    // int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==1) dp[i][j]=0;
    //             else if(i==0 && j==0) dp[i][j]=1;
    //             else{
    //                 int up = 0;
    //                 int left = 0;
    //                 if(i>0) up=dp[i-1][j];
    //                 if(j>0) left=dp[i][j-1];
    //                 dp[i][j]=(up+left)%mod;
    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    //     // int n=grid.size();
    //     // int m=grid[0].size();
    //     // vector<int> prev(n,0);
    //     // for(int i=0;i<n;i++){
    //     //     vector<int> curr(n,0);
    //     //     for(int j=0;j<m;j++){
    //     //         if(grid[i][j]==1) curr[j]=0;
    //     //         else if(i==0 && j==0) curr[j]=1;
    //     //         else{
    //     //             int up = 0;
    //     //             int left = 0;
    //     //             if(i>0) up=prev[j];
    //     //             if(j>0) left=curr[j-1];
    //     //             curr[j]=(up+left)%mod;
    //     //         }
    //     //     }
    //     //     prev=curr;
    //     // }
    //     // return prev[n-1];
    // }
    int helper(vector<vector<int>>& obs,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0 || obs[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=helper(obs,i-1,j,dp);
        int left=helper(obs,i,j-1,dp);
        return dp[i][j]=(up+left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(grid,m-1,n-1,dp);
    }
};