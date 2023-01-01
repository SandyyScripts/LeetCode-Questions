class Solution {
public:
    bool isHappy(int n) {
        if(n<10){
            if(n==1 || n==7) return true;
            else return false;
        }
        long long sum = 0;
        while(n>0){
            int l=n%10;
            sum+=l*l;
            n=n/10;
        }
        return isHappy(sum);
    }
};