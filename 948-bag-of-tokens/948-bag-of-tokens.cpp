class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int ans=0;
        int score=0;
        if(tokens[0]>power) return 0;
        int i=0,j=n-1;
        if(n==1) j==0;
        while(i<j){
            // cout<<"I ran"<<endl;
            if(power>tokens[i]){
                int currp = tokens[i];
                power-=currp;
                score++;
                i++;
            }
            else{
                score--;
                power+=tokens[j];
                j--;
            }
            // ans=max(ans,score);
        }
        if(power>=tokens[j]){
            // ans++;
            score++;
        }
        return score;
    }
};