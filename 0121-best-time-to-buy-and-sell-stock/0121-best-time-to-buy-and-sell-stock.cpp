class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> a,b;
        int m1=INT_MAX,m2=INT_MIN;
        for(int i=0;i<prices.size();i++){
            m1=min(m1,prices[i]);
            m2=max(m2,prices[prices.size()-i-1]);
            a.push_back(m1);
            b.push_back(m2);
        }
        reverse(b.begin(),b.end());
        int ans=0;
        // for(auto x:b){
        //     cout<<x<<" ";
        // }
        for(int i=0;i<prices.size()-1;i++){
            ans=max(ans,b[i+1]-a[i]);
        }
        return ans;
    }
};