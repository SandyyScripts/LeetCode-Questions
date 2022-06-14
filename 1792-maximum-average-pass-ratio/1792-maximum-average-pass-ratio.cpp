class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> q;
        
        for(int i=0;i<classes.size();i++){
            double a=(float)(classes[i][0]+1)/(float)(classes[i][1]+1)-(float)classes[i][0]/(float)classes[i][1];
            q.push(make_pair(a,i));
        }
        for(int j=0;j<extraStudents;j++){
            int i=q.top().second;
            classes[i][0]++;
            classes[i][1]++;
            double a=(float)(classes[i][0]+1)/(float)(classes[i][1]+1)-(float)classes[i][0]/(float)classes[i][1];
            q.pop();
            q.push(make_pair(a,i));
        }
        
        double ans=0;
        for (int i=0;i<classes.size();i++){
            ans+=(float)classes[i][0]/(float)classes[i][1];
        }
        return ans/classes.size();
    }
};