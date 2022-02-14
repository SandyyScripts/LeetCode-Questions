class Solution {
public:
    void DFS(vector<vector<int>> rooms,int s,vector<bool> &visited){
        visited[s]=true;
        for(auto x:rooms[s]){
            if(visited[x]==false)
                DFS(rooms,x,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        DFS(rooms,0,visited);
        for(auto tf:visited){
            if(!tf){
                return false;
            }
        }
        return true;
    }
};