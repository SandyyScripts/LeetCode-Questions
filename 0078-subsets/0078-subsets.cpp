class Solution {
public:
    void generateAll(vector<int>& nums,vector<vector<int>> &powerset,vector<int> &res,int idx){
        if(idx>=nums.size()){
            powerset.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        generateAll(nums,powerset,res,idx+1);
        res.pop_back();
        generateAll(nums,powerset,res,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> res;
        generateAll(nums,powerset,res,0);
        return powerset;
    }
};