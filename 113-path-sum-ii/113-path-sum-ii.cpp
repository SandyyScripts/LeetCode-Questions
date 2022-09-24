/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<vector<int>> &ans,vector<int> path,int x,int curr){
        if(!root) return;
        if(!root->left && !root->right && curr==x){
            ans.push_back(path);
            return;
        }
        if(root->left!=NULL){
            path.push_back(root->left->val);
            // cout<<root->left->val<<" ";
            dfs(root->left,ans,path,x,curr+root->left->val);
            path.pop_back();
        }
        if(root->right!=NULL){
            path.push_back(root->right->val);
            dfs(root->right,ans,path,x,curr+root->right->val);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if(!root) return ans;
        path.push_back(root->val);
        dfs(root,ans,path,targetSum,root->val);
        return ans;
    }
};