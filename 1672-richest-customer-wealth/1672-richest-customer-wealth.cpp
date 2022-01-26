class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        int ans=0;
        for(int i=0;i<accounts.size();i++){
            sum=0;
            for(int j=0;j<accounts[0].size();j++){
                sum=sum+accounts[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};