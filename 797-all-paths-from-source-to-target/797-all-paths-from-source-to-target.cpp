class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;   
        DFS(graph,ans,0,path);
        return ans;
    }
    void DFS(vector<vector<int>> &graph,vector<vector<int>> &ans,int s,vector<int> &path){
        path.push_back(s);
        if(s==graph.size()-1){
            ans.push_back(path);
        }
        else{
            vector<int> data=graph[s];
            for(auto x:data){
              DFS(graph,ans,x,path);
            }
        }
        path.pop_back();
    }
};