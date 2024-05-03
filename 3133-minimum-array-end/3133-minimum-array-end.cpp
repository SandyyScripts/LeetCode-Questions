class Solution {
public:
    long long minEnd(int n, int x) {
       long long ans = x;
    //    n--;
       long long t = n-1;
       int j = 0;
       for(int i = 0;i<62;i++){
            cout<<ans<<' '<<i<<endl;
            if(!(ans&((long long)1<<i))){// check ith bit of ans if on/off
                cout<<i<<'y'<<j<<endl;
                cout<<ans<<endl;
                if(t&((long long)1<<j)){ //// check jth bit of t if on/off
                    ans = ans|((long long)1<<i); // set the ith bit of ans;
                    t = t& ~((long long)1<<j); //unset jth bit of t
                }
                cout<<ans<<endl;
                if(!t)break;
                j++;
            }
            
       }
       return ans; 
    }
};