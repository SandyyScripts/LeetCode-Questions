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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l=calh(root->left);
        int r=calh(root->right);
        int currD=l+r;
        int LD=diameterOfBinaryTree(root->left);
        int RD=diameterOfBinaryTree(root->right);
        
        return max(max(LD,RD),currD);
    }
   int calh(TreeNode* root){
       if(root==NULL){
           return 0;
       }
       return max(calh(root->left),calh(root->right))+1;
   }
};