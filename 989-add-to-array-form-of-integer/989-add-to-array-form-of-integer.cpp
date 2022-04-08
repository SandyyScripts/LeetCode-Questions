class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> arr;
        int carry=0;
        for(int i=n-1;i>=0;i--){
            num[i]=num[i]+k%10+carry;
            arr.push_back(num[i]%10);
            k=k/10;
            carry=num[i]/10;
        }
        k=k+carry;
        while(k!=0){
            arr.push_back(k%10);
            k=k/10;
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};