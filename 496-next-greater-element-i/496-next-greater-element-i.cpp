class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        for(auto x:nums2){
            while(!s.empty() && s.top()<x){
                int y = s.top();
                s.pop();
                mp[y]=x;
            }
            s.push(x);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
                nums1[i]=mp[nums1[i]];
            }
            else{
                nums1[i]=-1;
            }
        }
        return nums1;
    }
};