class Solution {
public:
    int helper(vector<vector<int>> &triangle,int i,int j,vector<vector<int>>& dp){
        if(j==triangle.size()-1){
            return triangle[j][i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[j][i]+helper(triangle,i,j+1,dp);
        int diagnol = triangle[j][i]+helper(triangle,i+1,j+1,dp);
        return dp[i][j]=min(down,diagnol);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1,vector<int> (triangle.size()+1,-1));
        return helper(triangle,0,0,dp);
    }
};