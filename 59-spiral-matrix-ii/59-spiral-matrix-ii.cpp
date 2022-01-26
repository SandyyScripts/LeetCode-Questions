class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,1));
        int row=n-1;
        int col=n-1;
        int rowS=0;
        int colS=0;
        int count=1;
        while(count<=n*n){
            for(int index=colS;count<=n*n && index<=col;index++){
                ans[rowS][index]=count;
                count++;
            }
            rowS++;
            for(int index=rowS;count<=n*n && index<=row;index++){
                ans[index][col]=count;
                count++;
            }
            col--;
            for(int index=col;count<=n*n && index>=colS;index--){
                ans[row][index]=count;
                count++;
            }
            row--;
            for(int index=row;count<=n*n && index>=rowS;index--){
                ans[index][colS]=count;
                count++;
            }
            colS++;
        }
        return ans;
    }
};