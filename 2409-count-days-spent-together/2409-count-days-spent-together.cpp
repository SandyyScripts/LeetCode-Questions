class Solution {
public:
    vector<int> months = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int td(string s){
        int m = (s[1] - '0') + (10*(s[0]-'0'));
        int d = (s[4] - '0') + (10*(s[3]-'0'));
        m--;
        while(m>0){
            d+=months[m];
            m--;
        }
        return d;
    }
    int countDaysTogether(string a, string b, string c, string d) {
        int s1 = td(a);
        int s2 = td(b);
        int s3 = td(c);
        int s4 = td(d);
        int ans=0;
        for(int i=0;i<367;i++){
            if(s1<=i && i<=s2 && s3<=i && i<=s4) ans++;
        }
        return ans;
    }
};