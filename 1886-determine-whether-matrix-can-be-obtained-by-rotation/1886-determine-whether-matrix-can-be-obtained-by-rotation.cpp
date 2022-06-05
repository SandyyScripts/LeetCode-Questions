class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        //To check for 0 rotations
        if(mat == target){
            return true;
        }
        int deg = 3; //Max Rotations possible are 3 
        //1 - 90 degrees, 2 - 270 degrees and 3 - 270 degrees 
        //So check after each rotation if the two matrices are equal or not  
        while(deg >= 0){
           //First find the Transpose of Matrix
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
            //Then reverse all the elements of each row column wise
            for(int i = 0; i < n; i++){
                int left = 0;
                int right = n-1;
                while(left <= right){
                    int temp = mat[i][left];
                    mat[i][left] = mat[i][right];
                    mat[i][right] = temp;
                    left++;
                    right--;
                }   
            } 
            if(mat == target){
                return true;
            }
            deg--;
        }
        return false;
    }
};