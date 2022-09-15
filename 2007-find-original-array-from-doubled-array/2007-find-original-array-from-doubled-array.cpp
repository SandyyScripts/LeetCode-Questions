class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        map<int,int> mp;
        sort(changed.begin(),changed.end());
        vector<int> arr;
        for(auto &x:changed) mp[x]++;
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0) continue;
            if(mp[changed[i]*2]==0) return {};
            arr.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return arr;
    }
};