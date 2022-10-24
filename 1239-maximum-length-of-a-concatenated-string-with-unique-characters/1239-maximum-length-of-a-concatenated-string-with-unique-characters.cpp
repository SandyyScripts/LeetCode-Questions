class Solution {
public:
    int f(vector<string>& arr,unordered_map<char,int> mp,int i){
        if(i==arr.size()) return 0;
        string c = arr[i];
        bool it=false;
        int a = f(arr,mp,i+1);
        for(auto x:c){
            if(mp[x]){
                it=true;
            }
            else mp[x]++;
        }
        int b = INT_MIN;
        if(!it) b = c.size()+f(arr,mp,i+1);
        return max(a,b);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mp;
        string ans="";
        return f(arr,mp,0);
    }
};