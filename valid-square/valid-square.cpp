class Solution {
public:
    double distance(vector<int>& p1,vector<int>& p2){
        int a=p1[0]-p2[0];
        int b=p1[1]-p2[1];
        return sqrt(a*a + b*b);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points={p1,p2,p3,p4};
        set<double> st;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                double dist=distance(points[i],points[j]);
                if(dist==0){
                    return false;
                }
                st.insert(dist);
            }
        }
        return st.size()==2;
    }
};
