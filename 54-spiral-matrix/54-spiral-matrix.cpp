class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int rowS=0;
        int rowE=row-1;
        int colS=0;
        int colE=col-1;
        int count = 0;
        int total=row*col;
        while(count<total){
            for(int index=colS;count < total && index<=colE;index++){
                ans.push_back(matrix[rowS][index]);
                count++;
            }
            rowS++;
            for(int index=rowS; count<total && index<=rowE;index++){
                ans.push_back(matrix[index][colE]);
                count++;
            }
            colE--;
            for(int index=colE;count<total && index>=colS;index--){
                ans.push_back(matrix[rowE][index]);
                count++;
            }
            rowE--;
            for(int index=rowE;count<total && index>=rowS;index--){
                ans.push_back(matrix[index][colS]);
                count++;
            }
            colS++;
        }
        return ans;
    }
};