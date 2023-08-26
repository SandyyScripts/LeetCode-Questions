class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int last = INT_MIN;
        int chain = 0;

        sort(pairs.begin(), pairs.end(), [](vector<int> const& a, vector<int> const& b){
            return a[0] < b[0];
        });

        for(auto & p : pairs)
        {
            if(last == INT_MIN || last < p[0])
                last = p[1], chain++;
            else if(last > p[1])
                last = p[1];
        }

        return chain;
    }
};