class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int ans=1;
        for(auto &x:s){
            unordered_map<char,int> mp2;
            if(mp[x]>0){
                mp=mp2;
                ans++;
                mp[x]++;
            }
            else mp[x]++;
        }
        return ans;
    }
};