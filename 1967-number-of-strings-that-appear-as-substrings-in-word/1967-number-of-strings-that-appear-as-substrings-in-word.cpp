class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(auto ch:patterns){
                if(word.find(ch)!=-1)
                count++;
            }  
        return count;
    }
};