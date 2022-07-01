class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans=0;    
        for(auto x:boxTypes){
            if(truckSize<0) break;
            ans+=min(truckSize,x[0])*x[1];
            truckSize-=x[0];
        }
        return ans;
    }
};