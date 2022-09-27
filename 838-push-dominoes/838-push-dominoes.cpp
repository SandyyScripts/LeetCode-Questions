class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> r(n,0),l(n,0);
        char prev = '.';
        int t=1;
        for(int i=0;i<n;i++){
            if(d[i]=='.'){
                if(prev=='R'){
                    r[i]=t;
                    t++;
                    continue;
                }
                prev=d[i];
            }
            else{
                t=1;
                prev=d[i];
            }
        }
        prev='.';
        t=1;
        for(int i=n-1;i>=0;i--){
            if(d[i]=='.'){
                if(prev=='L'){
                    l[i]=t;
                    t++;
                    continue;
                }
                prev=d[i];
            }
            else{
                t=1;
                prev=d[i];
            }
        }
        string ans="";
        // cout<<r[0]<<" "<<l[0]<<endl;
        for(int i=0;i<n;i++){
            if(r[i]==l[i]){
                ans+=d[i];
            }
            else if(r[i]==0 && l[i]>0) ans+="L";
            else if(l[i]==0 && r[i]>0) ans+="R";
            else if(r[i]>l[i]){
                ans+="L";
            }
            else{
                ans+="R";
            }
        }
        return ans;
    }
};