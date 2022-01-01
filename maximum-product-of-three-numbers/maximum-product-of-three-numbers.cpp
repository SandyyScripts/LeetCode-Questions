class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=nums.size()-1;
        int product=1;
        int count=3;
        while(count>0){
            product=product*nums[last];
            last--;
            count--;
        }
        int ap=nums[0]*nums[1]*nums[nums.size()-1];
        if(product<ap){
            product=ap;
        }
        return product;
    }
};