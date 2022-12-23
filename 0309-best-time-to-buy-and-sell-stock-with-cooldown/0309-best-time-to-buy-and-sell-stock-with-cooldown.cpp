class Solution {
public:
    int f(int i,vector<vector<int>> &dp,bool p,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][p]!=-1) return dp[i][p];
        int profit=0;
        if(p){
            int t = -prices[i] + f(i+1,dp,false,prices);
            int l = f(i+1,dp,p,prices);
            profit = max(t,l);
        }
        else{
            int t = prices[i] + f(i+2,dp,true,prices);
            int l = f(i+1,dp,p,prices);
            profit = max(t,l);
        }
        return dp[i][p]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        return f(0,dp,true,prices);
    }
};