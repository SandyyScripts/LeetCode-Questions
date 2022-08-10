class Solution {
public:
    vector<int> findOrder(int nC, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){
            vector<int> result;
            for(int i=nC-1;i>=0;i--){
                result.push_back(i);
            }
            return result;
        }
        vector<vector<int>> adj(nC);
        vector<int> ind(nC,0);
        for(auto &x:prerequisites){
            adj[x[1]].push_back(x[0]);
            ind[x[0]]++;
        }
        queue<int> q;
        unordered_set<int> vis;
        for(int i=0;i<nC;i++){
            if(ind[i]==0) q.push(i);
        }
        int count=0;
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            if(vis.find(x)!=vis.end()) continue;
            vis.insert(x);
            count++;
            for(auto &y:adj[x]){
                ind[y]--;
                if(ind[y]==0){
                    q.push(y);
                }
            }
        }
        if(count!=nC){
            vector<int> noans;
            return noans;
        }
        return ans;
    }
};