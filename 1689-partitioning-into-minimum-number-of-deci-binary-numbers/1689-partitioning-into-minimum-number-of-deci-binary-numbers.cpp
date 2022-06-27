class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto m:n) ans=max(ans,m-'0');
        return ans;
    }
};