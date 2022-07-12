class Solution {
public:
    bool helper(vector<int> &arr,vector<int> &sides,int i,int side){
        if(i==arr.size()) return true;
        for(int j=0;j<4;j++){
            if(sides[j]+arr[i]<=side){
                sides[j]+=arr[i];
                if(helper(arr,sides,i+1,side)) return true;
                sides[j]-=arr[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto x:matchsticks) sum+=x;
        if(sum%4!=0 || matchsticks.size()<4) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater <>());
        int side=sum/4;
        vector<int> sides(4,0);
        return helper(matchsticks,sides,0,side);
    }
};