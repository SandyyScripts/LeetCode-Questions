class Solution {
public:
    unordered_map<int, int> subtreeCount;
    unordered_map<int, int> answer;
    
    int dfs1(int node, vector<vector<int>> &adjList, vector<bool> &visited){
        visited[node] = true;
        int count = 1;
        for(auto u: adjList[node]){
            if(!visited[u]){
                count += dfs1(u, adjList, visited);
            }
        }
        return subtreeCount[node] = count;
    }

    void dfs2(int node, vector<vector<int>> &adjList, vector<bool> &visited){
        visited[node] = true;
        for(auto u: adjList[node]){
            if(!visited[u]){
                // cout<<u<<" "<<node<<" "<<answer[node]<<endl;
                answer[u] = answer[node] + (subtreeCount[0] - subtreeCount[u]) - subtreeCount[u];
                dfs2(u, adjList, visited);
            }
        }
    }

    int bfs(int node, vector<vector<int>> &adjList, vector<bool> &visited ){
        queue<int> q;
        visited[node] = true;
        q.push(node);
        int level = 0;
        int sum = 0;

        while(!q.empty()){
            int t = q.size();
            while(t--){
                int curr = q.front();
                q.pop();

                for(auto u: adjList[curr]){
                    if(!visited[u]){
                        visited[u] = true;
                        q.push(u);
                    }
                }
                sum+=level;
            }
            level++;
        }
        return sum;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> rval(n);
        vector<vector<int>> adjList(n);
        for(auto c: edges){
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(c[0]);
        }
        vector<bool> visited(n, false);

        // Run BFS(DFS can also be used) for root Node to calculate initial answer
        answer[0] = bfs(0, adjList, visited);

        // Run DFS to calculate the subtree Count
        visited.assign(n, false);
        dfs1(0, adjList, visited);
 
        // Run DFS to calculate the answer for each node
        visited.assign(n, false);
        dfs2(0, adjList, visited);

        for(auto c: answer)
            rval[c.first] = c.second;

        return rval;
    }
};