class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp,mp2;
        for(auto x:p) mp2[x]++;
        int i=0,j=0;
        vector<int> ans;
        int k = p.size();
        while(j<s.size()){
            mp[s[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(mp==mp2) ans.push_back(i);
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                j++;
            }
        }
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        return ans;
    }
};