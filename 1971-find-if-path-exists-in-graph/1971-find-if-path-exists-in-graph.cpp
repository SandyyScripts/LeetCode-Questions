class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int> adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(s);
        vector<bool> visited(n+1,false);
        visited[s]=true;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            for(auto y:adj[num]){
                if(visited[y]==false){
                    q.push(y);
                    visited[y]=true;
                }
            }
            if(visited[d])
                return true;
        }
        return visited[d];
    }
};