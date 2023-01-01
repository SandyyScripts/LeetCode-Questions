class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        string word;
        stringstream total(s);
        
        while(total>>word)
            v.push_back(word);
        if(v.size()!=p.size()) return false;
        
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;
        
        for(int i=0;i<v.size();i++){
            if(mp.find(p[i])!=mp.end() && mp[p[i]]!=v[i]) return false;
            else if(mp2.find(v[i])!=mp2.end() && mp2[v[i]]!=p[i]) return false;
            mp[p[i]]=v[i];
            mp2[v[i]]=p[i];
        }
        return true;
    }
};