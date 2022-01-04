class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start=0;
        int end=cardPoints.size()-k;
        int total=0;
        int ans=0;
        while(k>0){
            ans=ans+cardPoints[cardPoints.size()-k];
            k--;
        }
        total=ans;
        while(end<cardPoints.size()){
            ans=ans+cardPoints[start]-cardPoints[end];
            start++;
            end++;
            if(ans>total){
                total=ans;
            }
        }
        return total;
    }
};