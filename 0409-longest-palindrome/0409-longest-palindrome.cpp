class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &x:s) mp[x]++;
        bool isodd = false;
        int ans = 0;
        for(auto &x:mp){
            if(x.second%2){
                ans+=x.second-1;
                if(!isodd){
                    ans+=1;
                    isodd = true;
                }
            }else{
                ans+=x.second;
            }
        }
        return ans;
    }
};