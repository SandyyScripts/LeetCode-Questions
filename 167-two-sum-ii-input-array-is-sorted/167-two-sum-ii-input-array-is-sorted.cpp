class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> arr;
        while(i<j){
            if(nums[i]+nums[j]==target){
                arr.push_back(i+1);
                arr.push_back(j+1);
                return arr;
            }
            else if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
        }
        return arr;
    }
};