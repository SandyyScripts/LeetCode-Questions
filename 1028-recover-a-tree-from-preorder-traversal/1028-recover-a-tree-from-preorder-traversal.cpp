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
    TreeNode* make(int i,int j,vector<pair<int,int>> &v){
        if(i>=j) return NULL;
        TreeNode * root = new TreeNode(v[i].second);
        if(i+1==j) return root;
        int md=j;
        for(int k=i+2;k<j;k++){
            if(v[k].first==v[i+1].first){
                md=k;
                break;
            }
        }
        root->left=make(i+1,md,v);
        root->right=make(md,j,v);
        return root;
    }
    TreeNode* recoverFromPreorder(string t) {
        int n=t.length();
        vector<pair<int,int>> ans;
        for(int i=0;i<n;){
            int dash=0,num=0;
            while(i<n && t[i]=='-'){
                dash++;
                i++;
            }
            while(i<n && t[i]!='-'){
                num=num*10+(t[i]-'0');
                i++;
            }
            ans.push_back({dash,num});
        }
        return make(0,ans.size(),ans);
    }
};