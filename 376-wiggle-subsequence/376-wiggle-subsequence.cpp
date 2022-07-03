class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int len=1;
        int prevdiff=0;
        int currdiff;
        for(int i=1;i<n;i++){
            currdiff=nums[i]-nums[i-1];
            if((currdiff>0 && prevdiff<=0) || (currdiff<0 && prevdiff>=0)){
                len++;
                prevdiff=currdiff;
            }
        }
        return len;
    }
};