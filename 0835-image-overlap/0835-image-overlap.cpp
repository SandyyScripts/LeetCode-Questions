class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img2.size();j++){
                if(img1[i][j]==1) v1.push_back({i,j});
                if(img2[i][j]==1) v2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        int ans=0;
        for(auto x:v1){
            for(auto y:v2){
                int i = x.first - y.first;
                int j = x.second - y.second;
                mp[{i,j}]++;
                ans=max(ans,mp[{i,j}]);
            }
        }
        return ans;
    }
};