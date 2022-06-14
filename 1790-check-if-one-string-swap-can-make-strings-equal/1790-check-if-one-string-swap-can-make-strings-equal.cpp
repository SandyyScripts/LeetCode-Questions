class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> m1,m2;
        for(auto x:s1)
            m1[x]++;
        for(auto y:s2)
            m2[y]++;
        if(s1==s2)
            return true;
        if(m1!=m2)
            return false;
        int diff=2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diff--;
            }
            if(diff<0)
                return false;
        }
        return true;
    }
};