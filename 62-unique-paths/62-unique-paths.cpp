class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        // for(auto x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m-1][n-1];   
    }
};

// class Solution {
// public:
//     int dp[101][101]{};
//     int uniquePaths(int m, int n) {
//         if(m==1 && n==1) return 1;
//         if(m<1 || n<1) return 0;
//         if(dp[m][n]) return dp[m][n];
//         int up = uniquePaths(m-1,n);
//         int down = uniquePaths(m,n-1);
//         return dp[m][n]=up+down;
//     }
// };