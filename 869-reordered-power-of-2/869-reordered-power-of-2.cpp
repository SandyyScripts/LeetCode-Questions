class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(),num.end());
        for(int i=0;i<30;i++){
            string temp = to_string(1<<i);
            sort(temp.begin(),temp.end());
            if(num==temp) return true;
        }
        return false;
    }
};