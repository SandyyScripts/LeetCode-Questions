class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string comb = s + s;
        for(int i=1;i<n;i++){
            string str = comb.substr(i,n);
            if(str==s) return true;
        }
        return false;
    }
};