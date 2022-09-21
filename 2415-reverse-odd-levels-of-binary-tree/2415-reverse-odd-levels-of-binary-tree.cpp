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
    void f(TreeNode* l,TreeNode* r,int level){
        if(!l || !r) return;
        if(level%2){
            int temp = l->val;
            l->val =r->val;
            r->val = temp;
        }
        f(l->left,r->right,level+1);
        f(r->left,l->right,level+1);
        
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        f(root->left,root->right,1);
        return root;
    }
};