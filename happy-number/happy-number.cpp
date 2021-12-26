class Solution {
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        do{
            slow=numsquare(slow);
            fast=numsquare(numsquare(fast));
            if(slow==1){
                return true;
            }
        }while(slow!=fast);
        return false;
    }
    int numsquare(int n){
        int ans=0;
        while(n>0){
            ans=ans+(n%10)*(n%10);
            n=n/10;
        }
        return ans;
    }
};