class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[1000];
        for(int i=0;i<n;i++){
            if(i<2) dp[i] = cost[i];
            else dp[i] = cost[i] + min(dp[i-2],dp[i-1]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};