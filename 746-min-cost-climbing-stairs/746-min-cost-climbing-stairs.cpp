class Solution {
public:
    int dp[1010];
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        return mincost(cost,n);
    }
    int mincost(vector<int>& cost,int n){
        if(dp[n]!=-1) return dp[n];
        return dp[n]=min(cost[n-1]+mincost(cost,n-1),cost[n-2]+mincost(cost,n-2));
    }
};