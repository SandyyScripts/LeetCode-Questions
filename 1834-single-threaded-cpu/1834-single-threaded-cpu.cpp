class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans;
        int i=0;
        int n = tasks.size();
        int et = tasks[i][0];
        while(i<n){
            if(!pq.empty()){
                et+=pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
            while(i<n and tasks[i][0]<=et){
                pq.push({tasks[i][1],tasks[i][2],tasks[i][0]});
                i++;
            }
            if(i<n and et<tasks[i][0] and pq.empty())
                et=tasks[i][0];
        }
        while(!pq.empty())
            ans.push_back(pq.top()[1]),pq.pop();
        return ans;
    }
};