class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto &y:dir){
                int i = x.first + y[0];
                int j = x.second + y[1];
                if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]==0) continue;
                if(mat[i][j]==-1){
                    mat[i][j]=mat[x.first][x.second]+1;
                    q.push({i,j});
                }
            }
        }
        return mat;
    }
};