class Solution {
public:
    int f(vector<vector<int>>& matrix,int j,int numSelect,unordered_map<int,int> mp,int ones){
        if(j==matrix[0].size()){
            if(numSelect==0) return ones;
            else return -1e9;
        }
        int take = -1e9;
        if(numSelect>0) take = f(matrix,j+1,numSelect-1,mp,ones);
        int count=0;
        for(int k=0;k<matrix.size();k++){
            if(mp[k]>0 || matrix[k][j]==1){
                mp[k]++;
            }
            else count++;
        }
        ones = min(ones,count);
        int leave = f(matrix,j+1,numSelect,mp,ones);
        return max(take,leave);
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        unordered_map<int,int> mp;
        if(matrix[0].size()==numSelect) return matrix.size();
        return f(matrix,0,numSelect,mp,1e8);
    }
};