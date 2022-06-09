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
    int check(TreeNode* root){
        int count=0;
        if(root==NULL)
            return 0;
        if(root->left!=NULL)
            count+=root->left->val;
        if(root->right!=NULL)
            count+=root->right->val;
        return count;
    }
    int sum=0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->val%2==0&&(root->left!=NULL||root->right!=NULL))
        {
            sum+=check(root->left);
            sum+=check(root->right);
        }
        int left=sumEvenGrandparent(root->left);
        int right=sumEvenGrandparent(root->right);
        return sum;
    }
};