class Solution {
public:
    int helper(string w){
        int val=0;
        int i=w.length()-1;
        for(auto x:w){
            val+= (x-'a')*(pow(10,i));
            i--;
        }
        return val;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a=helper(firstWord);
        int b=helper(secondWord);
        int c=helper(targetWord);
        if((a+b)==c){
            return true;
        }
        return false;
    }
};