class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0,j=colors.size()-1;
        int ans=0;
        while(j!=i){
            if(colors[i]!=colors[j]){
                ans=max(ans,abs(i-j));
            }
            j--;
        }
        j=colors.size()-1;
        while(i!=j){
            if(colors[i]!=colors[j]){
                ans=max(ans,abs(i-j));
            }
            i++;
        }
        return ans;
    }
};