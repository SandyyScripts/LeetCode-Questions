class Solution {
public:
    bool isPowerOfThree(int n) {
        return n==1 || (n>0 && n%3==0 && isPowerOfThree(n/3));
    }
};