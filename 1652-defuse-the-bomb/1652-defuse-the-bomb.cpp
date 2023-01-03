class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> arr(code.size(),0);
        if(k==0) return arr;
        for(int i=0;i<code.size();i++){
            int j=i;
            int sum=0;
            int m=0;
            while(m<abs(k)){
                if(k>0) sum+=code[(code.size()+j+1)%code.size()];
                else sum+=code[(code.size()+i-m-1)%code.size()];
                j++;
                m++;
            }
            arr[i]=sum;
        }
        return arr;
    }
};