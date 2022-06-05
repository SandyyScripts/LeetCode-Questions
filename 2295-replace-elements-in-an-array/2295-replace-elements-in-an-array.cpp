class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto x:operations){
            nums[mp[x[0]]]=x[1];
            mp[x[1]]=mp[x[0]];
        }
        return nums;
    }
};