class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n+1,0);
        for(auto num:trust){
            ans[num[0]]--;
            ans[num[1]]++;
        }
        for(int i=1;i<=n;i++){
            int data=ans[i];
            if(data==n-1)
                return i;
        }
        return -1;
    }
};