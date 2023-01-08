class Solution {
public:
    int mySqrt(int x) {
        long start=1;
        long end = x/2;
        long ans;
        while(start<=end){
            long mid = start + (end-start)/2;
            if(mid*mid==x){
                return mid;
            }
            if(mid*mid>x){
                end=mid-1;
            }
            if(mid*mid<x){
                start=mid+1;
                ans=mid;
            }
            
        }
        return ans;
    }
};