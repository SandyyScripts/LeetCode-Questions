class Solution {
public:
    bool isValid(int i){
        int num=i,rem;
        while(num!=0){
            rem=num%10;
            if(rem==0 || i%rem!=0) return false;
            num/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++){
            if(isValid(i)) res.push_back(i);
        }
        return res;
    }
};