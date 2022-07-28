class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int j=1;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word1[i]==word2[j]) dp[i+1][j+1]=dp[i][j];
                else{
                    int in = 1+ dp[i+1][j];
                    int rem = 1+dp[i][j+1];
                    int rep = 1+dp[i][j];
                    dp[i+1][j+1]=min(in,min(rem,rep));
                }
            }
        }
        return dp[n][m];
    }
    // int helper(int i,int j,string word1,string word2){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;
    //     if(word1[i]==word2[j]) return helper(i-1,j-1,word1,word2);
    //     int in = 1+helper(i,j-1,word1,word2);
    //     int rem = 1+helper(i-1,j,word1,word2);
    //     int rep = 1+helper(i-1,j-1,word1,word2);
    //     return min(in,min(rem,rep));
    // }
    // int minDistance(string word1, string word2) {
    //     return helper(word1.size()-1,word2.size()-1,word1,word2);
    // }
};