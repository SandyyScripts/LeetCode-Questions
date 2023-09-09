class Solution {
public:
    int helper(int i,vector<int> &nums,int target,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(i<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int leave = helper(i-1,nums,target,dp);
        int take = 0;
        if(nums[i]<=target) take=helper(nums.size()-1,nums,target-nums[i],dp);
        return dp[i][target]=leave + take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return helper(nums.size()-1,nums,target,dp);
    }
};