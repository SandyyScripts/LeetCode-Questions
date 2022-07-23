class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int count=capacity;
        for(int i=0;i<plants.size();i++){
            if(count>=plants[i]){
                ans+=1;
                count-=plants[i];
            }
            else{
                ans+=2*i+1;
                count=capacity;
                count-=plants[i];
            }
        }
        return ans;
    }
};