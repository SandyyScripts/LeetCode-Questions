class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0]+nums[1]+nums[nums.size()-1];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int curr_i = i+1;
            int curr_j = nums.size()-1;
            int ans = 0;
            while(curr_i<curr_j){
                ans = nums[curr_i]+nums[curr_j]+nums[i];
                if(target>ans) curr_i++;
                else if(ans>target) curr_j--;
                else curr_i++;
                if(abs(target-result)>abs(target-ans)){
                    result=ans;
                }
            }
        }
        return result;
    }
};