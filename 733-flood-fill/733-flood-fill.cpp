class Solution {
public:
    
   bool isvalid(vector<vector<int>>& image, int n, int m,int sr,int sc,int prev){
        if(sr>=0 && sc>=0 && sr<n && sc<m && image[sr][sc]==prev){
            return true;
        }
        return false;
    } 
    void nimage(vector<vector<int>>& image, int n, int m, int newColor,int sr,int sc ,int prev){
        image[sr][sc]=newColor;
        if(isvalid(image,n,m,sr+1,sc,prev)){
            nimage(image,n,m,newColor,sr+1,sc,prev);
        }
        if(isvalid(image,n,m,sr-1,sc,prev)){
            nimage(image,n,m,newColor,sr-1,sc,prev);
        }
        if(isvalid(image,n,m,sr,sc+1,prev)){
            nimage(image,n,m,newColor,sr,sc+1,prev);
        }
        if(isvalid(image,n,m,sr,sc-1,prev)){
            nimage(image,n,m,newColor,sr,sc-1,prev);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        int n=image.size();
        int m=image[0].size();
        nimage(image,n,m,newColor,sr,sc,image[sr][sc]);
        return image;
    }
};