class Solution {
public:
    int numDifferentIntegers(string word) {
        int i=0,ans=0;
        unordered_map<string,int> mp;
        while(i<word.size()){
            if((word[i]-'0')<=9){
                ans++;
                int x=0;
                string num="";
                bool z=false;
                while((word[i]-'0')<=9 && i<word.size()){
                    if(!z && (word[i]-'0')==0){
                         i++;
                         continue;
                    }
                    else{
                        num+=word[i];
                        i++;
                        z=true;
                    }
                }
                if(mp.find((num))!=mp.end()) ans--;
                mp[(num)]++;
            }
            i++;
        }
        return ans;
    }
};