class Solution {
public:
    int dp[601][101][101];
    pair<int,int> count(string &s){
        int a=0,b=0;
        for(auto &x:s){
            if(x=='1') a++;
            else b++;
        }
        return {b,a};
    }
    int helper(vector<string> &strs,int m,int n,int i,int ans){
        if(i<0) return 0;
        int take = -1e9;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        auto num = count(strs[i]);
        if(num.first<=m and num.second<=n) take = 1 + helper(strs,m-num.first,n-num.second,i-1,ans+1);
        int leave = helper(strs,m,n,i-1,ans);
        return dp[i][m][n]=max(take,leave);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        return helper(strs,m,n,strs.size()-1,ans);
    }
};