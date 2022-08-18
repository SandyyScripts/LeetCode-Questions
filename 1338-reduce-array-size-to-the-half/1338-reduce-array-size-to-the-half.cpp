class Solution {
public:
    int minSetSize(vector<int>& ar) {
        unordered_map<int,int> mp;
        int n=ar.size();
        for(auto &x:ar) mp[x]++;
        vector<int> arr;
        for(auto &x:mp) arr.push_back(x.second);
        sort(arr.begin(),arr.end());
        int ans=0;
        int i=mp.size()-1;
        int count=0;
        while(i>=0){
            ans+=arr[i];
            count++;
            if(ans>=n/2){
                return count;
            }
            i--;
        }
        return -1;
    }
};