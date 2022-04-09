class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minhp;
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto x:nums)
            mp[x]++;
        for(auto i=mp.begin();i!=mp.end();i++){
            minhp.push({i->second,i->first});
            if(minhp.size()>k)
                minhp.pop();
        }
        while(minhp.size()>0){
            res.push_back(minhp.top().second);
            minhp.pop();
        }
        return res;
    }
};