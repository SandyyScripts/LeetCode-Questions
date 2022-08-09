class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long,long long> mp;
        for(auto &x:arr) mp[x]++;
        long long result=0;
        long long mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            long long ans=0;
            for(int j=1;j<=sqrt(arr[i]);j++){
                if(arr[i]%j==0){
                    ans+=(mp[j]*mp[arr[i]/j])%mod;
                    if(arr[i]/j!=j){
                        ans+=(mp[j]*mp[arr[i]/j])%mod;
                    }
                }
            }
            mp[arr[i]]+=ans;
            // fmap[num] = ways;
            ans+=1;
            result = (result + ans) % 1000000007;
        }
        // for(auto &x:mp) result+=x.second%mod;
        return result;
     }
};