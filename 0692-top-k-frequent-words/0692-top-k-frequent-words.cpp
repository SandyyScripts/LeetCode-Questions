class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        map<int,int> mp2;
        priority_queue<pair<int,string>> pq;
        for(auto x:words){
            mp[x]++;
        }
        for(auto x:mp){
                pq.push({x.second,x.first});
                mp2[x.second]++;
        }
        int s = k;
        while(k>0){
            auto x = pq.top();
            int i = mp2[x.first];
            vector<string> arr;
            while(i>0){
                auto y = pq.top();
                arr.push_back(y.second);
                pq.pop();
                i--;
            }
            sort(arr.begin(),arr.end());
            for(auto x:arr){
                if(k>0){
                    ans.push_back(x);
                    k--;
                }
            }
            // k--;
            if(s==ans.size()) return ans;
        }
        return ans;
    }
};