class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums) mp[x]++;
        int ans=0;
        int c=0;
        for(auto &x:mp){
            if(x.second>c){
                ans=x.first;
                c=x.second;
            }
        }
        return ans;
    }
};