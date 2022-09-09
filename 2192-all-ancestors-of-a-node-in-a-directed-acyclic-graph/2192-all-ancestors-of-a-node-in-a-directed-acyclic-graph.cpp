class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,false);
        queue<int> q;
        vector<int> indegree(n,0);
        vector<int> adj[n];
        
        for(auto &x:edges){
            indegree[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        set<int> st[n];
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto &y:adj[x]){
                st[y].insert(x);
                for(auto &b:st[x]) st[y].insert(b);
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                }
            }
        }
        vector<vector<int>> ans(n,vector<int> ());
        for(int i=0;i<n;i++){
            ans[i]=vector<int> (st[i].begin(),st[i].end());
        }
        return ans;
    }
};