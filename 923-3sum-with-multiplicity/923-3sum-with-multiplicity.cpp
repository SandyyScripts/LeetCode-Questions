class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long long> map(105);
        for(auto x: arr) map[x]++;
        long long ans=0;
        for(int i=0;i<=100;i++){
            if(i*3==target) ans+=(map[i]*(map[i]-1)*(map[i]-2))/6;
            for(int j=i+1;j<=100;j++){
                int k=target-i-j;
                if (target == i * 2 + j) 
					ans += (map[i] * (map[i] - 1)) / 2 * map[j];
				else if (target == i + j * 2) 
					ans += (map[j] * (map[j] - 1)) / 2 * map[i];
				else if (k > j && k <= 100) 
					ans += map[i] * map[j] * map[k];
            }
            ans %= 1000000007;
        }
        return int(ans);
    }
};