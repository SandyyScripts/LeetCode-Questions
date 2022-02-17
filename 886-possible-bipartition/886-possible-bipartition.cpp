class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>v(n+1);
        vector<int>vis(n + 1, 0);
        for (int i = 0; i < dislikes.size(); i++)
        {
            int x, y;
            x = dislikes[i][0];
            y = dislikes[i][1];
            v[y].push_back(x);
            v[x].push_back(y);
        }
        
        for (int k = 1; k <= n; k++) {
            if (vis[k] != 0)continue;
            queue<int>d;
            d.push(k);
            vis[k]=1;
            while (d.size() != 0) {
                int size = d.size();
                int temp = d.front();
                d.pop();
                for (int i = 0; i < v[temp].size(); i++) {
                    if (vis[v[temp][i]] == vis[temp]) {
                        return false;
                    }
                    else if(vis[v[temp][i]]==0) {
                        vis[v[temp][i]] = -vis[temp];
                        d.push(v[temp][i]);
                    }

                }
            }
        }
        return true;
    }
};