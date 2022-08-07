class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char,long long> mp;
        vector<char> arr={'a','e','i','o','u'};
        for(auto &x:arr) mp[x]++;
        int count=5;
        if(n==1) return count;
        long long mod=1e9+7;
        for(int i=2;i<=n;i++){
            unordered_map<char,long long> mp1;
            for(int j=0;j<5;j++){
                if(arr[j]=='a') mp1[arr[j]]=mp['e']%mod;
                else if(arr[j]=='e') mp1[arr[j]]=(mp['a']%mod+mp['i']%mod)%mod;
                else if(arr[j]=='i') mp1[arr[j]]=(mp['e']%mod+mp['a']%mod+mp['o']%mod+mp['u']%mod)%mod;
                else if(arr[j]=='o') mp1[arr[j]]=(mp['i']%mod+mp['u']%mod)%mod;
                else mp1[arr[j]]=mp['a']%mod;
            }
            mp=mp1;
        }
        long long ans=0;
        for(auto &x:mp) ans=(ans+x.second)%mod;
        return ans;
    }
};