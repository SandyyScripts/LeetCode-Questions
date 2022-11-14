class Solution {
public:
    void f(vector<vector<int>> &stones,vector<bool> &visited,int vertex){
        if(visited[vertex]) return;
        visited[vertex]=1;
        for(int i=0;i<visited.size();i++){
            if(i!=vertex && (stones[i][0]==stones[vertex][0] || stones[i][1]==stones[vertex][1])){
                f(stones,visited,i);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                f(stones,visited,i);
            }
        }
        return n-ans;
    }
};