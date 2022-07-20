class Solution {
public:
    int helper(int i,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e8;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int leave = helper(i-1,amount,coins,dp);
        int take = INT_MAX;
        if(coins[i]<=amount) take=1+helper(i,amount-coins[i],coins,dp);
        return dp[i][amount]=min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        // int ans=helper(coins.size()-1,amount,coins,dp);
        // if(ans>=1e8) return -1;
        // return ans;
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e8;
        }
        for(int i=1;i<coins.size();i++){
            for(int t=0;t<=amount;t++){
                int leave = dp[i-1][t];
                int take = INT_MAX;
                if(coins[i]<=t) take=1+dp[i][t-coins[i]];
                dp[i][t]=min(take,leave);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e8) return -1;
        return ans;
    }
};