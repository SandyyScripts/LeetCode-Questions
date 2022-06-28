class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        vector<bool> f(s.length(),false);
        int count=0;
        for(auto x:mp){
            if(f[x.second]){
                while(f[x.second] && x.second!=0){
                    x.second--;
                    count++;
                }
            }
            f[x.second]=true;
        }
        return count;
    }
};