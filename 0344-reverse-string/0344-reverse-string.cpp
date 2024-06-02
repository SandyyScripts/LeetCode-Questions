class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0;
        while(i<n/2){
            int temp = s[n-1-i];
            s[n-1-i] = s[i];
            s[i] = temp;
            i++;
        }
    }
};