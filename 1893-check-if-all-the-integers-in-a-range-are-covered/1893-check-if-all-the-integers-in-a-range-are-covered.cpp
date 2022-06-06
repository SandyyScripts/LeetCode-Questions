class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> vec(51,0);
        for(auto x:ranges){
            for(int i=x[0];i<=x[1];i++){
                vec[i]=1;
            }
        }
        for(int i=left;i<=right;i++){
            if(vec[i]==0){
                return false;
            }
        }
        return true;
    }
};