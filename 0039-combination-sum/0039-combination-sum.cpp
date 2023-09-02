class Solution {
public:
    void helper(vector<vector<int>> &final_ans,vector<int> &ans,vector<int>& candidates,int target,int idx){
        if(idx>=candidates.size()){
            if(target==0) final_ans.push_back(ans);
            return;
        }
        if(candidates[idx]<=target){
            ans.push_back(candidates[idx]);
            helper(final_ans,ans,candidates,target-candidates[idx],idx);
            ans.pop_back();
        }
        helper(final_ans,ans,candidates,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> final_ans;
        vector<int> ans;
        helper(final_ans,ans,candidates,target,0);
        return final_ans;
    }
};