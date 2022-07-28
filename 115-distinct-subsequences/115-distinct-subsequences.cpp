class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size()+1,vector<double> (t.size()+1,0));
        for(int i=0;i<s.size()+1;i++) dp[i][0]=1;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                else dp[i+1][j+1] = dp[i][j+1];
            }
        }
        return (int)dp[s.size()][t.size()];
    }
    // int helper(int i,int j,string s,string t){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(s[i]==t[j]){
    //         return helper(i-1,j-1,s,t)+helper(i-1,j,s,t);
    //     }
    //     return helper(i-1,j,s,t);
    // }
    // int numDistinct(string s, string t) {
    //     return helper(s.size()-1,t.size()-1,s,t);
    // }
};