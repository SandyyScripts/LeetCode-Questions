class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> cost(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<bool> vis(n+1,false);
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            int currCost = p.first;
            int currNode = p.second;
            pq.pop();
            if(vis[currNode]) continue;
            vis[currNode]=true;
            cost[currNode]=currCost;
            for(int i=0;i<adj[currNode].size();i++){
                int nextnode = adj[currNode][i].first;
                int nextcost = adj[currNode][i].second;
                if(vis[nextnode]) continue;
                pq.push({currCost+nextcost,nextnode});
           } 
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(vis[i]==false) return -1;
        }
        for(auto y:cost){
            // cout<<y<<" ";
            ans=max(ans,y);
        }
        return ans;
    }
};