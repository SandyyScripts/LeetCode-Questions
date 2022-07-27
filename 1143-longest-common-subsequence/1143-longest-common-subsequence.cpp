class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,0));
        for(int i=0;i<text1.length();i++){
            for(int j=0;j<text2.length();j++){
                if(text1[i]==text2[j]) dp[i+1][j+1]=1+dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
    // int f(int i,int j,string text1,string text2,vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] = 1+f(i-1,j-1,text1,text2,dp);
    //     return dp[i][j]=max(f(i,j-1,text1,text2,dp),f(i-1,j,text1,text2,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
    //     return f(text1.length()-1,text2.length()-1,text1,text2,dp);
    // }
};