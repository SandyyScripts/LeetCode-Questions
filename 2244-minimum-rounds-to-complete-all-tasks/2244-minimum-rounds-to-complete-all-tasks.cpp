class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int count=0;
        for(auto &x:tasks) mp[x]++;
        for(auto &x:mp){
            int y = x.second;
            if(y==1) return -1;
            if(y%3==0) count+=y/3;
            // else if(y%2==0) count+=y/2;
            else{
                count+=y/3;
                count++;
            }
        }
        return count;
    }
};