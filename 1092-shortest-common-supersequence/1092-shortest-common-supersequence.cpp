class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        string ans="";
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int i = s1.size();
        int j = s2.size();
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};