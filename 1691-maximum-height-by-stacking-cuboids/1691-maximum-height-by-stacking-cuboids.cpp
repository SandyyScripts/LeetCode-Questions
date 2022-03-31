class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &c:cuboids) sort(c.begin(),c.end());
        sort(cuboids.begin(),cuboids.end());
        int ans=0;
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]){
                    dp[i]=max(dp[i],cuboids[i][2]+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};