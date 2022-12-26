class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cR = 0;
        for(int i=0;i<nums.size();i++){
            if(cR<i) return false;
            cR=max(cR,i+nums[i]);
        }
        return true;
    }
};