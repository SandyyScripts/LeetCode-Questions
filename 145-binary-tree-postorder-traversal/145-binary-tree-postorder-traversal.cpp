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
    void post(vector<int>&res, TreeNode*root){
        if(root == NULL){
            return;
        }
        
        post(res,root->left);
        post(res,root->right);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>res;
        post(res,root);
        
        return res;
    }
};