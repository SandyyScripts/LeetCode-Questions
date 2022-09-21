class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<vector<int>> v(1, vector<int>(26));
        vector<int> cnt(1);
        for(auto x : words){
            int s = 0;
            for(char c : x){
                int y = c - 'a';
                int &z = v[s][y];
                if(!z){
                    z = v.size();
                    v.emplace_back(vector<int>(26));
                    cnt.emplace_back();
                }
                s = z;
                cnt[s]++;
            }
        }
        
        vector<int> ans;
        for(auto x : words){
            int z = 0, s = 0;
            for(char c : x){
                int y = c - 'a';
                s = v[s][y];
                z += cnt[s];
            }
            ans.emplace_back(z);
        }
        return ans;
    }
};