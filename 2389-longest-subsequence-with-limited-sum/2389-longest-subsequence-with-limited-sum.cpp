class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),m=queries.size();
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int f = queries[i];
            int s=0,e=n-1,m;
            while(e-s>1){
                m = s + (e-s)/2;
                if(nums[m]>f) e =m-1;
                else s=m;
            }
            if(nums[e]<=f){
                ans[i]=e+1;
            }
            else if(nums[s]<=f){
                ans[i]=s+1;
            }
            else{
                ans[i]=0;
            }
        }
        return ans;
    }
};