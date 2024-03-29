class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        while(--n){
            for(int i=3;i>=0;i--){
                dp[i]+=dp[i+1];
            }
        }
        int ans=0;
        for(auto &x:dp){
            ans+=x;
        }
        return ans;
    }
};


//best solution \U0001f44c
//     int countVowelStrings(int n) {
//         int a=1, e=1, i=1, o=1, u=1;
        
//         while(--n){
//             o += u;
//             i += o;
//             e += i;
//             a += e;
//         }
        
//         return a+e+i+o+u;
//     }