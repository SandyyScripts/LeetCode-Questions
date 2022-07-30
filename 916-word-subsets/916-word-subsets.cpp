class Solution {
public:
    bool check(string y,unordered_map<char,int> mp){
        for(auto &x:y){
            if(mp[x]) mp[x]--;
        }
        for(auto &x:mp){
            // cout<<x.second<<" ";
            if(x.second) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> mp;
        
        for(auto &x:words2){
            unordered_map<char,int> mp2;
            for(auto &z:x) {
                mp2[z]++;
            }
            for(auto &z:x) {
                if(!mp[z]) mp[z]++;
                else mp[z]=max(mp[z],mp2[z]);
            }
            
        }
        vector<string> ans;
        for(auto &y:words1){
            if(check(y,mp)) ans.push_back(y);
        }
        return ans;
    }
};