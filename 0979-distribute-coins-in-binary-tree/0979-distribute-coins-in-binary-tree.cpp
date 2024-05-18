class Solution {
public:
    int distributeCoins(TreeNode* root) {
        TreeNode dummy;
        return dfs(root, &dummy);
    }
    
private:
    int dfs(TreeNode* cur_node, TreeNode* parent) {
        if (cur_node == nullptr) {
            return 0;
        }
        int moves = dfs(cur_node->left, cur_node) + dfs(cur_node->right, cur_node);
        int from_this = cur_node->val - 1;
        parent->val += from_this;
        moves += abs(from_this);
        return moves;
    }
};