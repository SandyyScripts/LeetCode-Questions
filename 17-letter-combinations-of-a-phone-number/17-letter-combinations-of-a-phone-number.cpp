class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        return total("",digits);
    }
    vector<string> total(string p,string up){
        if(up.length()==0){
            vector<string> an; 
            an.push_back(p);
            return an;
        }
        vector<string> ans;
        
        int digit=stoi(up.substr(0,1));
        if(digit<7){
            for(int i=(digit-2)*3;i<(digit-1)*3;i=i+1){
            char ch = (char)('a'+i);
            vector<string> adde=total(p+ch,up.substr(1));
            for(int j=0;j<adde.size();j++){
                ans.push_back(adde[j]);
            }
        }
        }
        if(digit==7){
            for(int i=(digit-2)*3;i<(digit-1)*3+1;i=i+1){
            char ch = (char)('a'+i);
            vector<string> adde=total(p+ch,up.substr(1));
            for(int j=0;j<adde.size();j++){
                ans.push_back(adde[j]);
            }
        }
        }
        if(digit==8){
            for(int i=(digit-2)*3+1;i<=(digit-1)*3;i=i+1){
            char ch = (char)('a'+i);
            vector<string> adde=total(p+ch,up.substr(1));
            for(int j=0;j<adde.size();j++){
                ans.push_back(adde[j]);
            }
        }
        }
        if(digit==9){
            for(int i=(digit-2)*3+1;i<=(digit-1)*3+1;i=i+1){
            char ch = (char)('a'+i);
            vector<string> adde=total(p+ch,up.substr(1));
            for(int j=0;j<adde.size();j++){
                ans.push_back(adde[j]);
            }
        }
        }
        return ans;
    }
};