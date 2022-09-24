class Solution {
public:
    void add(int x,unordered_map<int,int>& mp){
        int i=0;
        while(x>0){
            int r=x%2;
            x/=2;
            if(r==1) mp[i]++;
            i++;
        }
    }
    void del(int x,unordered_map<int,int>& mp){
        int i=0;
        while(x>0){
            int r=x%2;
            x/=2;
            if(r==1){
                mp[i]--;
                if(mp[i]==0) mp.erase(i);
            }
            i++;
        }
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=n-1;
        int j=n-2;
        vector<int> ans(n,1);
        add(nums[i],mp);
        while(j>=0){
            add(nums[j],mp);
            while(i>j){
                int prev = mp.size();
                del(nums[i],mp);
                int new_val = mp.size();
                if(prev==new_val) i--;
                else{
                    add(nums[i],mp);
                    break;
                }
            }
            int s = i-j+1;
            ans[j]=s;
            j--;
        }
        return ans;
    }
};