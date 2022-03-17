class Solution {
public:
    int dp[45];
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        long long ans=tn(n);
        return ans;
    }
    long long tn(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=tn(n-1)+tn(n-2)+tn(n-3);
    }
};