class Solution {
public:
    void helper(int n,int k,int prev,vector<int> &ans){
        if(n==0){
            ans.push_back(prev);
            return;
        }
        int a = abs((prev%10)-k);
        int b = abs((prev%10)+k);
        if(k==0){
            helper(n-1,k,prev*10 + a,ans);
            return;
        }
        if((prev%10)>=k && a>=0 && a<10) helper(n-1,k,prev*10 + a,ans);
        if( b>=0 && b<10) helper(n-1,k,prev*10 + b,ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            helper(n-1,k,i,ans);
        }
        return ans;
    }
};