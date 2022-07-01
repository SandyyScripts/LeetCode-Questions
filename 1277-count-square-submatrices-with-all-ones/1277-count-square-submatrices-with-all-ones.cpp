class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]!=0){
                    int minnum = min(matrix[i-1][j-1],matrix[i-1][j]);
                    matrix[i][j]=min(minnum,matrix[i][j-1])+1;
                }
                else{
                    matrix[i][j]=0;
                }
            }
        }
        for(auto &x:matrix){
            for(auto &y:x){
                ans+=y;
            }
        }
        return ans;
    }
};