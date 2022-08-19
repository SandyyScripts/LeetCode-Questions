class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        for(auto &x:nums) m1[x]++;
        for(auto &x:nums){
            if(m1[x]==0) continue;
            m1[x]--;
            if(m2[x-1]>0){
                // m1[x]--;
                m2[x-1]--;
                m2[x]++;
            }
            else if(m1[x+1]!=0 && m1[x+2]!=0){
                m1[x+1]--;
                m1[x+2]--;
                m2[x+2]++;
            }
            else return false;
        }
        return true;
    }
};