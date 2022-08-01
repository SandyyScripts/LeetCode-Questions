class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                    int profit=0;
                    if(buy){
                        int take = -prices[i] + dp[i+1][0];
                        int leave = dp[i+1][buy];
                        profit=max(take,leave);
                    }
                    else{
                        int take = dp[i+1][1]+prices[i];
                        int leave = dp[i+1][buy];
                        profit = max(take,leave);
                    }
                    dp[i][buy]=profit;
            }
        }
        // for(auto &x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][1];
    }
    // int f(int i,bool buy,vector<int> &prices){
    //     if(i==prices.size()) return 0;
    //     int profit=0;
    //     if(buy){
    //         int take = -prices[i] + f(i+1,false,prices);
    //         int leave = f(i+1,buy,prices);
    //         profit=max(take,leave);
    //     }
    //     else{
    //         int take = f(i+1,true,prices)+prices[i];
    //         int leave = f(i+1,buy,prices);
    //         profit = max(take,leave);
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     return f(0,true,prices);
    // }
};