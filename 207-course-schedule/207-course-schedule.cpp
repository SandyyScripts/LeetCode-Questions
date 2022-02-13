class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> dirAdj[n], visited(n,0), curCallVisited(n,0);
        
		//Create an adjacency matrix from given array
        for(auto& pairCourse: prerequisites){
            int u = pairCourse[0], v = pairCourse[1];
            dirAdj[u].push_back(v);
        }
        
		//Detect cycle
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                if(containsCycleDFS(i, dirAdj, n, visited, curCallVisited)) return false;
            }
        }
        return true;
    }
    
    bool containsCycleDFS(int node, vector<int> dirAdj[], int n, vector<int>& visited, vector<int>& curCallVisited){
        visited[node] = 1;
        curCallVisited[node] = 1;
        
        vector<int> neighbors = dirAdj[node];
        
        for(auto& num:neighbors){
            if(visited[num] == 0){
                if(containsCycleDFS(num, dirAdj, n, visited, curCallVisited)) return true;
            }
            else if(curCallVisited[num] == 1) return true;
        }
        curCallVisited[node] = 0;
        return false;
    }
};