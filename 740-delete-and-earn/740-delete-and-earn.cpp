class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxe=*max_element(nums.begin(),nums.end());
        int dp[20005];
        vector<int> freq(10005);
        for(auto i:nums) freq[i]++;
        
        dp[1]=freq[1];
        dp[2]=max(dp[1],freq[2]*2);
        for(int i=3;i<=maxe;i++){
            dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);
        }
        return dp[maxe];
    }
};