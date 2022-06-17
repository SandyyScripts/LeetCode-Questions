class Solution {
public:
    vector<vector<int>> ans;
    int help(vector<int> &st,int time,int i){
        if(i>=st.size()){
            return 0;
        }
        if(ans[time][i]!=-1){
            return ans[time][i];
        }
        return ans[time][i]=max(st[i]*time+help(st,time+1,i+1),help(st,time,i+1));
    }
    int maxSatisfaction(vector<int>& st) {
        ans=vector<vector<int> > (600,vector<int>(600,-1));
        sort(st.begin(),st.end());
        return help(st,1,0);
    }
};