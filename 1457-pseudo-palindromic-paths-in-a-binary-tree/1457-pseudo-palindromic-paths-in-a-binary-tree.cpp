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
    int f(TreeNode* root,vector<int> arr){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            arr[root->val]++;
            int isodd=0;
            for(auto &x:arr){
                if(x%2) isodd++;
                if(isodd>1) return 0;
            }
            if(isodd>1) return 0;
            return 1;
        }
        arr[root->val]++;
        return f(root->left,arr)+f(root->right,arr);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10,0);
        return f(root,arr);
    }
};