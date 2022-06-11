class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int y:nums){
            sum+=y;
        }
        sum=sum-x;
        int curr_sum=0;
        int i=0,j=0;
        bool found = false;
        int ml=0;
        for(i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            while(j<=i && curr_sum>sum){
                curr_sum-=nums[j];
                j++;
            }
            if(curr_sum==sum){
                found=true;
                ml=max(ml,i-j+1);
            }
        }
        return found ? nums.size() - ml : -1;
    }
};