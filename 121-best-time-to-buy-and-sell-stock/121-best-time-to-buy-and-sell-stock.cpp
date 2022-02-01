class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else if(prices[i]-mini>maxprofit){
                maxprofit=prices[i]-mini;
            }
        }
        return maxprofit;
    }
};