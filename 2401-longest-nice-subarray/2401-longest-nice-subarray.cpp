class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int a = 0;
        while(j<nums.size()){
            int x = a&nums[j];
            if(x==0){
                ans=max(ans,j-i+1);
                a|=nums[j];
                j++;
            }
            else{
                a^=nums[i];
                i++;
            }
        }
        return ans;
    }
};