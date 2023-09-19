class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> total(1e5+1,false);
        for(int i=0;i<nums.size();i++){
            if(total[nums[i]]==true) return nums[i];
            total[nums[i]]=true;
        }
        return -1;
    }
};