class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long bt) {
        int i=0,j=0;
        int n=ct.size();
        vector<long long> p(n);
        p[0]=rc[0];
        for(int k=1;k<n;k++) p[k]=rc[k]+p[k-1];
        multiset<int> s;
        int maxi=0;
        for(int i=0;i<n;i++){
            s.insert(ct[i]);
            long long count;
            if(j!=0) count=*(s.rbegin())+(i-j+1)*(p[i]-p[j-1]);
            else count = *(s.rbegin())+(i+1)*(p[i]);
            
            if(count<=bt) maxi=max(i-j+1,maxi);
            else{
                while(j<=i){
                    s.erase(s.find(ct[j]));
                    j++;
                    if(i<j) break;
                    long long count2=*(s.rbegin())+(i-j+1)*(p[i]-p[j-1]);
                    if(count2>bt) continue;
                    else break;
                }
            }
        }
        return maxi;
    }
};