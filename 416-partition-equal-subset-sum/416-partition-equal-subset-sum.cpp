class Solution {
public:
    bool f(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(nums[i]<=target) take=f(i-1,target-nums[i],nums,dp);
        bool leave=f(i-1,target,nums,dp);
        return dp[i][target]=take || leave;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(auto x:nums) totalSum+=x;
        if(totalSum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int> (totalSum+1,-1));
        return f(nums.size()-1,totalSum/2,nums,dp);
    }
};