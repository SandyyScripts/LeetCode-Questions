class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string temp="";
        vector<string> arr;
        for(auto x:s){
            if(x==' '){
                arr.push_back(temp);
                temp="";
            }
            else temp+=x;
        }
        arr.push_back(temp);
        string ans="";
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
            if(i==0) break;
            ans+=" ";
        }
        return ans;
    }
};