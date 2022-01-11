class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i,0);
                count++;
                i++;
            }
        }
        while(count!=0){
            arr.pop_back();
            count--;
        }
    }
};