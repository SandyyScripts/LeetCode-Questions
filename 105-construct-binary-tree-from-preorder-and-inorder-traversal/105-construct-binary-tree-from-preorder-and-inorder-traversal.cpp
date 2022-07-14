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
    TreeNode* rec(int l, int r) {
        if (l > r) return NULL;
        
        int i = 0;
        while (m_inorder[i] != m_preorder[m_curr]) {
            i++;
        }

        m_curr++;
        TreeNode* node = new TreeNode(m_inorder[i]);
        node->left = rec(l, i-1);
        node->right = rec(i+1, r);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m_preorder = preorder, m_inorder = inorder;
        return rec(0, preorder.size()-1);
    }
    
private:
    int m_curr = 0;
    vector<int> m_preorder, m_inorder;
};