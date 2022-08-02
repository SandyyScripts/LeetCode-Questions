class Solution {
public:
    int f(int i,bool buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit=0;
        if(buy){
            int take = -prices[i] + f(i+1,false,cap,prices,dp);
            int leave = f(i+1,buy,cap,prices,dp);
            profit=max(take,leave);
        }
        else{
            int take = f(i+1,true,cap-1,prices,dp)+prices[i];
            int leave = f(i+1,buy,cap,prices,dp);
            profit = max(take,leave);
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return f(0,true,k,prices,dp);
    }
};