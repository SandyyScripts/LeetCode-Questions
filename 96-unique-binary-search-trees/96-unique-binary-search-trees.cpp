class Solution {
public:
    int f(vector<int> &dp,int n){
        if(n==1) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += (f(dp,i-1)*f(dp,n-i));
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        return f(dp,n);
    }
};