class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pt(2);
        pt[0].push_back(1);
        for(int i=1;i<=rowIndex;i++){
            pt[1].push_back(1);
            for(int j=1;j<pt[0].size();j++){
                pt[1].push_back(pt[0][j]+pt[0][j-1]);
            }
            pt[1].push_back(1);
            pt[0]=pt[1];
            pt[1].clear();
        }
        return pt[0];
    }
};