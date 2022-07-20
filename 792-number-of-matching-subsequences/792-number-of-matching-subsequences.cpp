class Solution {
public:
    bool helper(string s,string w){
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==w[k]) k++;
            if(k==w.size()) return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto &x:words) mp[x]++;
        int count=0;
        for(auto x:mp){
            if(helper(s,x.first)) count+=x.second;
        }
        return count;
    }
};