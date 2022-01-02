class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.size()==0){
           return strs[0];
       }
       string result = "";
        string temp=strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].length()<temp.length()){
                temp=strs[i];
            }
        }
        bool flag=true;
        for(int i=0;i<temp.length();i++){
            flag=true;
            for(int j=0;j<strs.size();j++){
                if(temp[i]==strs[j][i]){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                result += temp[i];
                continue;
            } else {
                break;
            }
        }
        return result;
    }
};