class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(auto x:nums)
            p.push(x);
        int ans=0;
        while(k--){
            ans=p.top();
            p.pop();
        }
        return ans;
    }
};