class Solution {
public:
    string toLowerCase(string s) {
        for(auto i=0;i<s.size();i++) s[i]=tolower(s[i]);
        return s;
    }
};