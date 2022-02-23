class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>> &grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        int ans=0;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        
        while(!q.empty()){
            int size_q=q.size();
            int temp=0;
            while(size_q!=0){
                pair<int,int> p=q.front();
                int x=p.first;
                int y=p.second;
                q.pop();
            
                int xp[4]={0,0,-1,1};
                int yp[4]={1,-1,0,0};
                for(int i=0;i<4;i++){
                   int xn=xp[i]+x;
                   int yn=yp[i]+y;
                
                    if(isValid(xn,yn,grid)){
                       q.push({xn,yn});
                       grid[xn][yn]=2; 
                       temp++;
                     }
                 
              }
              size_q--;
            }
             if(temp!=0){
                time++;
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    time=0;
                    break;
                }
            }
        }
        return (time==0)?-1:time;
    }
};