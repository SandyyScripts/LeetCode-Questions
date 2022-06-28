class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int> ans;
        for(auto x:nums1){
            int index=mp[x];
            int p=0;
            for(int i=index+1;i<nums2.size();i++){
                if(nums2[i]>x){
                    ans.push_back(nums2[i]);
                    p++;
                    break;
                }
            }
            if(!p){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};