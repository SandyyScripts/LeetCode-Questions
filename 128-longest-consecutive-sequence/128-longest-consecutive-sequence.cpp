class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        int ans=0;
        int prev=0;
        bool isprev=false;
        int result=-1;
        for(auto y:m){
            cout<<y.first<<endl;
            if(!isprev){
                prev=y.first;
                isprev=true;
                continue;
            }
            if(abs(y.first-prev)==1){
                cout<<ans<<endl;
                prev=y.first;
                ans++;
                continue;
            }
            prev=y.first;
            result=max(ans,result);
            ans=0;
        }
        result=max(ans,result);
        return result+1;
    }
};