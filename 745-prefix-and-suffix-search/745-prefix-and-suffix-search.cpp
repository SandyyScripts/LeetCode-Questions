class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string w=words[i];
            int wordSize=w.size();
            for(int j=1;j<=wordSize;j++){
                string pre = w.substr(0,j);
                for(int k=0;k<wordSize;k++){
                    string suf=w.substr(k,wordSize);
                    mp[pre+"|"+suf]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+"|"+suffix;
        return mp[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */