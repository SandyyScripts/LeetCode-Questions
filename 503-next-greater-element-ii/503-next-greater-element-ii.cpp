class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size()*2-1;i++){
            while(!s.empty() && nums[s.top()]<nums[i%nums.size()]){
                ans[s.top()]=nums[i%nums.size()];
                s.pop();
            }
            s.push(i%nums.size());
        }
        return ans;
    }
};