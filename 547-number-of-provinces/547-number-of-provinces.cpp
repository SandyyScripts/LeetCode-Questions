class Solution {
public:
    void dfs(int s,int n,vector<bool> &visited,vector<vector<int>> &isConnected){
        visited[s]=true;
        vector<int> adj;
        for(int i=0;i<n;i++){
            int x = isConnected[s][i];
            if(x==1)
                adj.push_back(i);
        }
        for(auto y:adj){
            if(!visited[y])
                dfs(y,n,visited,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(isConnected.size(),false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,n,visited,isConnected);
            }
        }
        return count;
    }
};