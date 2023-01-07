class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int> mp;
        int ans=0;
        while(j<s.length()){
            if(mp[s[j]]==0){
                mp[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
            }
        }
        
        return ans;
    }
};