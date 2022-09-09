class Solution {
public:
    bool static s(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),s);
        int maxe = INT_MIN;
        int ans=0;
        for(int i=p.size()-1;i>=0;i--){
            if(p[i][1]<maxe) ans++;
            else maxe=p[i][1];
        }
        return ans;
    }
};