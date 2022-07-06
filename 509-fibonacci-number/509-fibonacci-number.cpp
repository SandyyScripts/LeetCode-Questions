class Solution {
public:
    int fib(int n) {
        if(n==2){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        int prev=1;
        int prev2=1;
        for(int i=3;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};