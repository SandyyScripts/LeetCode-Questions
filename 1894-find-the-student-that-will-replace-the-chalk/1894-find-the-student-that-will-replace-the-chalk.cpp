class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto x:chalk){
            sum+=x;
        }
        long long remChalk = k%sum;
        for(int i=0;i<chalk.size();i++){
            remChalk-=chalk[i];
            if(remChalk==0){
                return i+1;
            }
            else if(remChalk<0){
                return i;
            }
        }
        return 0;
    }
};