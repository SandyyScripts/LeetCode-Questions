class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int ans=0;
        for(auto x:nums){
            if(mp[x]>0){
                ans+=mp[x]-1;
            mp[x]--;
            }
        }
        return ans;
    }
};