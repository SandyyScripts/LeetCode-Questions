class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int count=0;
        int r = s.size();
        int c = s[0].size();
        for(int i=0;i<c;i++){
            for(int j=0;j<r-1;j++){
                if(s[j][i]>s[j+1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};