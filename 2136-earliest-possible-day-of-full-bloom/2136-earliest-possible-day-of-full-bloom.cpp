class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        for(int i=0;i<plantTime.size();i++){
            arr.push_back({plantTime[i],growTime[i]});
        }
        sort(arr.begin(),arr.end(),comp);
        int start=0,ans=0;
        for(int i=0;i<plantTime.size();i++){
            start+=arr[i].first;
            ans=max(ans,start+arr[i].second);
        }
        return ans;
    }
}; 