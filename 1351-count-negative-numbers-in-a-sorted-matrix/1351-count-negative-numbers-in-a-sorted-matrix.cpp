class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            int s=0;
            int e=grid[i].size()-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(grid[i][mid] >= 0){
                    s = mid + 1;
                }
                else if(grid[i][mid] < 0){
                    count = count + (e-mid) + 1;
                    e = mid - 1;
                }
                mid = s + (e-s)/2;
            }
        }
        return count;
    }
};