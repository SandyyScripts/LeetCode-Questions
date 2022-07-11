class Solution {
public:
    int dp[101][101]{};
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        if(m<1 || n<1) return 0;
        if(dp[m][n]) return dp[m][n];
        int up = uniquePaths(m-1,n);
        int down = uniquePaths(m,n-1);
        return dp[m][n]=up+down;
    }
};