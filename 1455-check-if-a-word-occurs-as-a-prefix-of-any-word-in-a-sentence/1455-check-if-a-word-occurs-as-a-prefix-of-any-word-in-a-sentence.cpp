class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> v;
        string x="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                v.push_back(x);
                x="";
                continue;
            }
            x+=sentence[i];
        }
        if(x!=""){
            v.push_back(x);
        }
        for(int i=0;i<v.size();i++){
            string y=v[i].substr(0,searchWord.size());
            if(y==searchWord){
                return i+1;
            }
        }
        return -1;
    }
};