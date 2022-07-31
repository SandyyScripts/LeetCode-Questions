class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        int c=1;
        int p=0;
        while(n>=c){
            n-=c;
            p++;
            c+=1;
        }
        return p;
    }
};