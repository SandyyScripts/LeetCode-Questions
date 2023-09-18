class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<mat.size();i++){
            int c = 0;
            for(auto &y:mat[i]){
                if(y==1) c++;
            }
            pq.push({c,i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto x = pq.top().second;
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};