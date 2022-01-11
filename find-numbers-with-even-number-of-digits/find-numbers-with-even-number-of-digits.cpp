class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int elements : nums){
            int numD=0;
            while(elements!=0){
                numD++;
                elements/=10;
            }
            if(numD%2==0){
                count++;
            }
        }
        return count;
    }
};