class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        unordered_map<int,int> mp,mp2;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp2.count(nums[i]) != 0){
                continue;
            }
            mp2[nums[i]]=i;
        }
        if(!mp[target]) return {-1,-1};
        int initial = mp2[target];
        int count = mp[target];
        return {initial,initial+count-1};
    }
};