class Solution {
public:
    int dp[310][10010];
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans=tways(coins.size()-1,amount,coins);
        return ans;
    }
    int tways(int idx,int amount,vector<int> &coins){
        if(amount==0) return 1;
        if(idx<0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int ways=0;
        for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[idx]){
            ways+=tways(idx-1,amount-coin_amount,coins);
        }
        return dp[idx][amount]=ways;
    }
        
};