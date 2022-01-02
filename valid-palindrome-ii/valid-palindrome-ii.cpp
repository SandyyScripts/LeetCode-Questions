class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return isp(s,i+1,j) || isp(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
    bool isp(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
};