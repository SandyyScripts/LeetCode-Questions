class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int left=1e9;
                    int up = 1e9;
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};