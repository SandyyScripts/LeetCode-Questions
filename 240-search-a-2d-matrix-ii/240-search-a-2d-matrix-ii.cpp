class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowi=0;
        int coli=col-1;
        while(rowi<row && coli>=0){
            int element = matrix[rowi][coli];
            if(element==target){
                return true;
            }
            if(target>element){
                rowi++;
            }
            else{
                coli--;
            }
        }
        return false;
    }
};