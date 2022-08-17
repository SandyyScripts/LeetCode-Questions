class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> vis(points.size(),false);
        vector<vector<int>> adj(points.size(),vector<int> (points.size(),0));
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                adj[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            }
        }

        int dist=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> x = pq.top();
            pq.pop();
            int currNode = x.second;
            int currCost = x.first;
            if(vis[currNode]) continue;
            vis[currNode]=true;
            dist+=currCost;
            for(int i=0;i<points.size();i++){
                // cout<<"I ran";
                int nNode = i;
                int nNodeCost = adj[currNode][i];
                if(vis[nNode]) continue;
                pq.push({nNodeCost,nNode});
            }
        }
        return dist;
    }
};