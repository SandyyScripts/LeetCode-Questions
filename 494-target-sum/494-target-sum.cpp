class Solution {
public:
    int findTargetSumWays(vector<int>& num, int d) {
         int tar=0;
            for(auto x:num) tar+=x;
            if(tar-d<0 || (tar-d)%2) return false;
            tar=(tar-d)/2;
             vector<int> prev(tar+1,0),curr(tar+1);
            if(num[0]==0) prev[0]=curr[0]=2;
            else prev[0]=1;
            if(num[0]!=0 && num[0]<=tar) prev[num[0]]=1;
                for(int i=1;i<num.size();i++){
                    for(int target=0;target<=tar;target++){
                        int take = 0;
                        if(num[i]<=target) take=prev[target-num[i]];
                        int leave = prev[target];
                        curr[target]=(take+leave);
                    }
                    prev=curr;
                }
                return prev[tar];
            }
};