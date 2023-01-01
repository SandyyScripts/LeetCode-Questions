class Solution {
public:
    int countDigits(int num) {
        string a = to_string(num);
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(num%(a[i]-'0')==0) ans++;
        }
        return ans;
    }
};