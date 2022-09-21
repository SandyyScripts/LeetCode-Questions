class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        int maxa=0;
        for(int i=0;i<s.size()-1;i++){
            // cout<<s[i+1]-s[i]<<" ";
            if(s[i+1]-s[i]==1){
                ans++;
            }
            else{
                maxa=max(maxa,ans);
                ans=1;
            }
        }
        maxa=max(maxa,ans);
        return maxa;
    }
};