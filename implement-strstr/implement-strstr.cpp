class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int m=haystack.length();
        int n=needle.length();
        if(m<n){
            return -1;
        }
        for(int i=0;i<=m-n;i++){
            int j;
            for(j=0;j<n;++j){
                if(haystack[j+i]!=needle[j]){
                    break;
                }
            }
             if(j==n){
                    return i;
                }
        }
        return -1;
    }
};