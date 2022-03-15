class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,lis(dp,i,nums));
        }
        return ans;
    }
    int lis(int dp[],int i,vector<int> &nums){
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans=max(ans,lis(dp,j,nums)+1);
            }
        }
        return dp[i]=ans;
    }
};