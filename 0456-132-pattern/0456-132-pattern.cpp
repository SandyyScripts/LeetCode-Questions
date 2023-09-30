class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> minv(nums.size());
        minv[0]=nums[0];
        for(int i=1;i<nums.size();i++){
           minv[i]=min(nums[i],minv[i-1]);
        }
        stack<int> st;
        for(int j=nums.size()-1;j>=0;j--){
            
            if(nums[j]>minv[j]){
                while(!st.empty() && st.top()<=minv[j]){
                    st.pop();
                }
                if(!st.empty() && st.top()<nums[j]){
                    return true;
                }
                st.push(nums[j]);
            }
        }
        return false;
    }
};