class Solution {
public:
    int mod = (int)1e9+7;
    int f(int s,int e,int k,vector<vector<int>> &dp){
        if(k==0){
            if(s==e) return 1;
            else return 0;
        }
        if(dp[s+2002][k]!=-1) return dp[s+2002][k];
        int forward = f(s+1,e,k-1,dp);
        int backward = f(s-1,e,k-1,dp);
        return dp[s+2002][k]=(forward+backward)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4004,vector<int> (1001,-1));
        return f(startPos,endPos,k,dp);
    }
};