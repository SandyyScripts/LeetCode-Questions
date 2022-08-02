class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &x:matrix){
            for(auto &y:x){
                pq.push(y);
            }
        }
        while(k-->1){
            pq.pop();
        }
        return pq.top();
    }
};