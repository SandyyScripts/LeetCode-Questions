class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1) return "";
        for(int i=0;i<p.size();i++){
            if(p[i]!='a' && (i)!=p.size()/2){
                p[i]='a';
                return p;
            }
        }
        p[p.size()-1]='b';
        return p;
    }
};