class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0,j = 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        while(i<s.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else return t[j];
        }
        return t[t.size()-1];
    }
};