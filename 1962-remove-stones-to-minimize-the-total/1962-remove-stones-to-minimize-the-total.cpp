class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int x = pq.top();
            pq.pop();
            x = x - x/2;
            pq.push(x);
            k--;
        }
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};