class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return 1;
        if(n%3!=0 || n==0) return 0;
        return isPowerOfThree(n/3);
    }
};