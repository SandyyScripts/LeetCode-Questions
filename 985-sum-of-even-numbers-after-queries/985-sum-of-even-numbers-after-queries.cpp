class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int esum = 0;
        for(auto &x:nums) if(x%2==0) esum+=x;
        vector<int> ans;
        for(auto &x:queries){
            int idx = x[1];
            int val = x[0];
            if(nums[idx]%2==0){
                esum-=nums[idx];
            }
            nums[idx]+=val;
            if(nums[idx]%2==0){
                esum+=nums[idx];
            }
            ans.push_back(esum);
        }
        return ans;
    }
};