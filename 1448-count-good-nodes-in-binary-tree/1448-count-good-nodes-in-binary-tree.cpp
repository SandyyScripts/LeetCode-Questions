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
    int dfs(TreeNode * root,int maxVal){
        if(root==NULL){
            return 0;
        }
        if(root->val>=maxVal){
            maxVal=max(root->val,maxVal);
            return 1+dfs(root->left,maxVal)+dfs(root->right,maxVal);
        }
        return dfs(root->left,maxVal)+dfs(root->right,maxVal);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};