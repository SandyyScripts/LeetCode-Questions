class Solution {
public:
    bool cycle(int s,vector<bool> &visited,vector<bool> &currv,vector<vector<int>> &graph,vector<bool> &pcycle){
        visited[s]=true;
        currv[s]=true;
        vector<int> data=graph[s];
        for(auto x:data){
            if(!visited[x]){
                if(cycle(x,visited,currv,graph,pcycle)){
                    return pcycle[s]=true;
                }
            }
            else if(visited[x]==true && currv[x]==true){
                    return pcycle[s]=true;
                }
        }
        currv[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        vector<bool> currv(n,false);
        vector<bool> pcycle(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cycle(i,visited,currv,graph,pcycle);
            }
        }
        for(int i=0;i<n;i++){
            if(!pcycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};