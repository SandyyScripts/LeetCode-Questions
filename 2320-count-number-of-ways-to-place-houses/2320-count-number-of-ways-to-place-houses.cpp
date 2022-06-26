class Solution {
public:
    int mod=1e9+7;
    int recur(int ind,vector<long long>& dp){
        if(ind==0){
            return 2;
        }
        if(ind<0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        return dp[ind]=(recur(ind-1,dp)+recur(ind-2,dp))%mod;
    }
    int countHousePlacements(int n) {
        vector<long long> dp(n,-1);
        long long x=recur(n-1,dp);
        return (x*x)%mod;
    }
};