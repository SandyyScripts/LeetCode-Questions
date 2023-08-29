class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n+1,0),postfix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1];
            if(customers[i-1]=='N')
                prefix[i]+=1;
        }
        for(int i=n-1;i>=0;i--){
            postfix[i]=postfix[i+1];
            if(customers[i]=='Y')
                postfix[i]+=1;
        }
        int min_penalty=1e8,idx=0;
        for(int i=0;i<=n;i++){
            if(min_penalty>prefix[i]+postfix[i]){
                min_penalty=prefix[i]+postfix[i];
                idx=i;
            }
        }
        return idx;
    }
};