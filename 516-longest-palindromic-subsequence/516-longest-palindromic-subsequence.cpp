class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2="";
        for(int i=s.length()-1;i>=0;i--){
            s2+=s[i];
        }
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,0));
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s2.length();j++){
                if(s[i]==s2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[s.length()][s.length()];
    }
};