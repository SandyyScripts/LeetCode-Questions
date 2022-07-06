class Solution {
public:
    int money(vector<int> &nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int left = prev;
            int curr = max(take,left);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=nums.size()-1) b.push_back(nums[i]);
        }
        return max(money(a),money(b));
    }
};