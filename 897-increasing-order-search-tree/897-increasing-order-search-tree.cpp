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
    TreeNode* curr=NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode* node=new TreeNode(0);
        curr=node;
        inorder(root);
        return node->right;
    }
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        root->left=NULL;
        curr->right=root;
        curr=root;
        inorder(root->right);
    }
};