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
    int findmax(vector<int>& nums, int low, int high){  // to find max element in given range
        int mx = low;
        while(low<=high){
            if(nums[mx] < nums[low])    mx = low;
            low++;
        }
        return mx;
    }
    
    TreeNode* constTree(vector<int>& nums, int low, int high){
        if(low>high)    return NULL;
        int idx = findmax(nums, low, high);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = constTree(nums, low, idx-1);
        root->right = constTree(nums, idx+1, high);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int idx = findmax(nums, 0, nums.size()-1);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = constTree(nums, 0, idx-1);
        root->right = constTree(nums, idx+1, nums.size()-1);
        return root;
    }
};