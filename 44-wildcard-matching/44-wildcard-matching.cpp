class Solution {
public:
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
    //     dp[0][0]=true;
    //     for(int j=1;j<=m;j++){
    //         int flag = true;
    //         for(int ii=1;ii<=j;ii++){
    //             if(p[ii-1]!='*'){
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         dp[0][j]=flag;
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(s[i]==p[j] || p[j]=='?') dp[i+1][j+1]=dp[i][j];
    //             else if(p[j]=='*'){
    //                  dp[i+1][j+1]= dp[i][j+1] || dp[i+1][j];
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }
        bool helper(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=helper(i-1,j-1,s,p,dp);
        else if(p[j]=='*'){
            return dp[i][j]=helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int> (p.size(),-1));
        return helper(s.size()-1,p.size()-1,s,p,dp);
    }
};