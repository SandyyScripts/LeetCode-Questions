class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=0;
        while(i<n){
            int j=i;
            while(j<n && nums[j]-nums[i]<=k){
                j++;
            }
            ans++;
            i=j;
        }
        return ans;
    }
};