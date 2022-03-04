class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int ans=minjump(nums,nums.size(),dp,0);
        return ans;
    }
    int minjump(vector<int> &nums,int n,vector<int> &dp,int i){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return INT_MAX;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int steps=INT_MAX;
        int max_jump=nums[i];
        for(int jump=1;jump<=max_jump;jump++){
            int next_cell=i+jump;
            int subprob = minjump(nums,n,dp,next_cell);
            if(subprob!=INT_MAX){
                steps=min(steps,subprob +1);
            }
        }
        return dp[i]=steps;
    }
};