class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> p;
        int i=0;
        for(auto y:arr){
            int num = abs(x-y);
            p.push_back({num,i});
            i++;
        }
        sort(p.begin(),p.end());
        vector<int> ans;
        
        for(auto y:p){
            if(k==0) break;
            ans.push_back(arr[y.second]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};