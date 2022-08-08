class Solution {
public:
    int sum(int num1, int num2) {
        unordered_map<int,int> mp;
        mp[num1]=num1;
        mp[num2]=num2;
        if(mp[num1]||mp[num2]) return mp[num1]+mp[num2];
        return 0;
    }
};