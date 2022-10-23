class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<bool> arr(nums.size()+1,false);
        for(int i=0;i<nums.size();i++){
            if(arr[nums[i]]) ans.push_back(nums[i]);
            arr[nums[i]]=true;
        }
        for(int i=1;i<=nums.size();i++){
            if(!arr[i]) ans.push_back(i);
        }
        return ans;
    }
};