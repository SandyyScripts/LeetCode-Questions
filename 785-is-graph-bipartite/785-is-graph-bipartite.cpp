class Solution {
public:
    bool bfs(vector<vector<int>>& graph,int i,vector<int> adj[],vector<int> &colour){
        queue<int> q;
        q.push(i);
        colour[i]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:adj[x]){
                if(colour[y]==-1){
                    colour[y]=1-colour[x];
                    q.push(y);
                }
                else if(colour[y]==colour[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        // for(auto x:graph){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> colour(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colour[i]==-1){
                if(!bfs(graph,i,adj,colour)){
                    return false;
                }
            }
        }
        return true;
    }
};