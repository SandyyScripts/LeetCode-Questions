class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0,c2=0;
        for(auto &x:word){
            if(int(x)>96){
                if(c2>1) return false;
                c++;
            }
            else{
                if(c>0) return false;
                c2++;
            }
        }
        return true;
    }
};