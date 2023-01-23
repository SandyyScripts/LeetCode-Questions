class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> a(n+1,0),b(n+1,0);
        for(auto &x:trust){
            a[x[1]]++;
            b[x[0]]++;
        }
        for(int i=0;i<=n;i++){
            if(a[i]==n-1 && b[i]==0) return i;
        }
        return -1;
    }
};