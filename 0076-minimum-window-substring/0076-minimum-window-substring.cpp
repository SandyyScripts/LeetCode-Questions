class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> mp;
        for(auto x:t) mp[x]++;
        int i=0,j=0,count=mp.size(),start=0;
        int ans = INT_MAX;
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
            if(count==0){
                while(count==0){
                    if(ans>j-i+1){
                        ans=j-i+1;
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count++;
                    i++;
                }
            }
            j++;
        }
        if(ans!=INT_MAX) return s.substr(start,ans);
        else return "";
    }
};