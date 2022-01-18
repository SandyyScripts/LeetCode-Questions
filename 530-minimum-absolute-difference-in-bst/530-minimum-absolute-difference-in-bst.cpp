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
    vector<int> ans;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int minnum=INT_MAX;
        for(int i=1;i<ans.size();i++){
            if(abs(ans[i-1]-ans[i])<minnum){
                minnum=abs(ans[i-1]-ans[i]);
            }
        }
        return minnum;
    }
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
};