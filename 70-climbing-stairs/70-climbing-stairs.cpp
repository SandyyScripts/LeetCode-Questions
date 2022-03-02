class Solution {
public:
    int dp[100]={0};
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=2;i++){
            ans+=climbStairs(n-i);
        }
        return dp[n]=ans;
    }
};