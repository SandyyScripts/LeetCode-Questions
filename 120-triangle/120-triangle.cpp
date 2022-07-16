class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagnol = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagnol);
            }
        }
        return dp[0][0];
    }
    //     int helper(vector<vector<int>> &triangle,int i,int j,vector<vector<int>>& dp){
    //     if(j==triangle.size()-1){
    //         return triangle[j][i];
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = triangle[j][i]+helper(triangle,i,j+1,dp);
    //     int diagnol = triangle[j][i]+helper(triangle,i+1,j+1,dp);
    //     return dp[i][j]=min(down,diagnol);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     vector<vector<int>> dp(triangle.size()+1,vector<int> (triangle.size()+1,-1));
    //     return helper(triangle,0,0,dp);
    // }
};