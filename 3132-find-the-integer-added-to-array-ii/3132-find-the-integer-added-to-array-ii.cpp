class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2,int x){
    int count = 0,i=0,j=0;
    while(i<nums1.size() and j<nums2.size()){
        if(nums2[j]-nums1[i]!=x){
            count++;
        }else {
            j++;
        }
        i++;
    }
        // cout<<count<<endl;
    return count<=2;
}

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = INT_MAX;
        int t = min(3,int(nums1.size()));
        // t = min(t,int(nums2.size()));
        for(int i=0;i<t;i++){
            int x = nums2[0]-nums1[i];
            if(check(nums1,nums2,x)){
                ans=min(ans,x);
            }
        }
        return ans;
    }
};