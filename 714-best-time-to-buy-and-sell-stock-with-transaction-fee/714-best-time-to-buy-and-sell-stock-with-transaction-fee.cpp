class Solution {
public:
    int f(int i,bool buy,vector<int> &prices,vector<vector<int>> &dp,int fee){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            int take = -prices[i]-fee + f(i+1,false,prices,dp,fee);
            int leave = f(i+1,buy,prices,dp,fee);
            profit=max(take,leave);
        }
        else{
            int take = f(i+1,true,prices,dp,fee)+prices[i];
            int leave = f(i+1,buy,prices,dp,fee);
            profit = max(take,leave);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return f(0,true,prices,dp,fee);
    }
};