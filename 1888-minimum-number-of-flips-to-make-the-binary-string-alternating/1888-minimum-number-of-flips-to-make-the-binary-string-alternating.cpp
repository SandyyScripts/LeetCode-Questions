class Solution {
public:
    int minFlips(string s) {
        //using sliding window technique
        int n = s.size(), res =INT_MAX, ans1 =0, ans2=0;
        string s1 , s2;
        s = s+s;
		//create 2 string stirng  of size s+s
        for(int i =0;i<s.size();i++)
        {
            s1 += i%2 == 0 ? '0' :'1';   // 0101010101... 
            s2 += i%2 == 0 ? '1' : '0';  //1010101010...
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(s1[i] != s[i]) ans1++; 
            if(s2[i] != s[i]) ans2++; 
            
            if(i >= n){
                //decrement the prev if it was a part of res
                if(s1[i-n] != s[i-n]) ans1--;
                if(s2[i-n] != s[i-n]) ans2--;
            }
            if(i >= n-1)
                res = min(res, min(ans1, ans2));
        }
        
        return res;
    }
};

