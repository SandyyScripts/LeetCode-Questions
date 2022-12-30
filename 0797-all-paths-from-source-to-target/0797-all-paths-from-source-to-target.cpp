class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph,path,ans,0);
        return ans;
    }
    void dfs(vector<vector<int>>& adj,vector<int> &path,vector<vector<int>> &ans,int s){
        path.push_back(s);
        if(s==adj.size()-1) ans.push_back(path);
        else{
            vector<int> d=adj[s];
            for(auto &x:d) dfs(adj,path,ans,x);
        }
        path.pop_back();
    }
};