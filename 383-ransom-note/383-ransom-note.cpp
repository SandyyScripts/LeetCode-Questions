class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        for(auto &x:magazine) mp1[x]++;
        for(auto &x:ransomNote){
            if(mp1[x]>0) mp1[x]--;
            else return false;
        }
        return true;
    }
};