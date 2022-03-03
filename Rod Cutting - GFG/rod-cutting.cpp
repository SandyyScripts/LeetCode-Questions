// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  // Top Down DP
    // int dp[1000]={0};
    // int cutRod(int price[], int n) {
    //     //code here
    //     if(n<=0){
    //         return 0;
    //     }
    //     if(dp[n]!=0){
    //         return dp[n];
    //     }
    //     int ans=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int cut =i+1;
    //         int current_ans=price[i] + cutRod(price,n-cut);
    //         ans=max(ans,current_ans);
    //     }
    //     return dp[n]=ans;
    // }
    int cutRod(int price[],int n){
        int dp[n+1];
        dp[0]=0;
        for(int len=1;len<=n;len++){
            int ans=INT_MIN;
            for(int i=0;i<len;i++){
                int cut=i+1;
                int current_ans = price[i] + dp[len - cut];
                ans = max(ans,current_ans);
            }
            
            dp[len]=ans;
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends