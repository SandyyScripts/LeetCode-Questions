class Solution {
public:
    bool static compare(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        priority_queue<int, vector<int>, greater<int>> unused;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++) unused.push(i);
        for(auto &x:meetings){
            int start = x[0];
            int end = x[1];
            while(engaged.size()>0 && engaged.top().first<=start){
                int y = engaged.top().second;
                unused.push(y);
                engaged.pop();
            }
            if(unused.size()>0){
                int y = unused.top();
                unused.pop();
                freq[y]++;
                engaged.push({end,y});
            }
            else{
                pair<long long, int> topmost = engaged.top();
                engaged.pop();
                freq[abs(topmost.second)]++;
                long long newEnd = topmost.first;
                newEnd += (end - start);
                
                /* Mark the room as engaged */
                engaged.push({newEnd, topmost.second});
            }
        }
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};