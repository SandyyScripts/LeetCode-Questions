class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,sum=0,res=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            if(mp[nums[j]]){
                while(mp[nums[j]]){
                    sum-=nums[i];
                    mp[nums[i]]--;
                    i++;
                }
            }
            else{
                sum+=nums[j];
                res=max(res,sum);
                mp[nums[j]]++;
                j++;
            }
        }
        return res;
    }
};