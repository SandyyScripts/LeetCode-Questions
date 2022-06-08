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
    int num=0;
    vector<int> helper(TreeNode* root){
        if(root==NULL){
            vector<int> arr(2,0);
            return arr;
        }
        vector<int> left=helper(root->left);
        vector<int> right=helper(root->right);
        int sum=left[0]+right[0]+root->val;
        int t=left[1]+right[1]+1;
        // cout<<sum<<" ";
        int avg=sum/t;
        if(root->val==avg){
            num++;
        }
        vector<int> arr(2,0);
        arr[0]=sum;
        arr[1]=t;
        return arr;
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return num;
    }
};