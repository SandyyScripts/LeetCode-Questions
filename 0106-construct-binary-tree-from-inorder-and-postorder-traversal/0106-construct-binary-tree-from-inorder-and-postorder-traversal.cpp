
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildtree(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,mp);
    }
    TreeNode* buildtree(int is,int ie,int ps,int pe,vector<int>& inorder,vector<int>& postorder,map<int,int> &mp){
        if(is>ie || ps>pe) return NULL;
        TreeNode* r = new TreeNode(postorder[pe]);
        int rootn = mp[postorder[pe]];
        int numl = rootn - is;
        r->left = buildtree(is,rootn-1,ps,ps+numl-1,inorder,postorder,mp);
        r->right = buildtree(rootn+1,ie,ps+numl,pe-1,inorder,postorder,mp);
        return r;
    }
};