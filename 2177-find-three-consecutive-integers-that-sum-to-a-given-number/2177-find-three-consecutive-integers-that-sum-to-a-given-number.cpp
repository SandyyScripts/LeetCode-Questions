class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x;
        vector<long long> ans;
        x=(num-3)/3;
        if(3*x+3==num){
            ans.push_back(x);
            ans.push_back(x+1);
            ans.push_back(x+2);
        }
        return ans;
    }
};