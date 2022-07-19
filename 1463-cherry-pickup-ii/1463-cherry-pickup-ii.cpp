class Solution {
public:
    int helper(int i,int j1,int j2,vector<vector<int>> &grid,vector < vector < vector < int >>> &dp){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        for(int d1=0;d1<3;d1++){
            for(int d2=0;d2<3;d2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else{
                    value=grid[i][j1]+grid[i][j2];
                }
                value+=helper(i+1,j1+d1-1,j2+d2-1,grid,dp);
                ans=max(value,ans);
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector < vector < vector < int >>> dp(grid.size(), vector < vector < int >> (grid[0].size(), 
  vector < int > (grid[0].size(), -1)));
        return helper(0,0,grid[0].size()-1,grid,dp);
    }
};