class Solution {
public:
    int dp[1001][1001]={0};
    int longestCommonSubsequence(string text1, string text2) {
        // int n1=text1.length();
        // int n2=text2.length();
        // vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return lcs(text1,text2,0,0);
    }
    int lcs(string &s1,string &s2,int i,int j){
        if(dp[i][j]!=0) return dp[i][j];
        if(i==s1.size() || j==s2.size()) return 0;
        if(s1[i]==s2[j]){
            return dp[i][j]=1+lcs(s1,s2,i+1,j+1);
        }
        int op1=lcs(s1,s2,i+1,j);
        int op2=lcs(s1,s2,i,j+1);
        dp[i][j]=max(op1,op2);
        return dp[i][j];
    }
};