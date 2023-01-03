class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int i=0;
        int n=words.size();
        while(i<n){
            if(words[(i+startIndex)%n]==target || words[(startIndex+n-i)%n]==target) return i; 
            i++;
        }
        return -1;
    }
};