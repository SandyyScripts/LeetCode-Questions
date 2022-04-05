class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=-1;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            if(height[i]<height[j]){
                maxarea=max(maxarea,height[i]*(j-i));
                i++;
            }
            else{
                maxarea=max(maxarea,height[j]*(j-i));
                j--;
            }
        }
        return maxarea;
    }
};