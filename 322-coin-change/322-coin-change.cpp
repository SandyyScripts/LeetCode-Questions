class Solution {
public:
    //Bottom Up Approach
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int c:coins){
                if(i-c>=0 and dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-c]+1);
                }
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};