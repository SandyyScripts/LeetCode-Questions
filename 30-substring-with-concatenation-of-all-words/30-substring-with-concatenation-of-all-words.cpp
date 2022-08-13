class Solution {
public:
    unordered_map<string,int> mp;
    void permute(vector<string>& a, int l, int r) { 
    // Base case 
    if (l == r){
        string s="";
        for(auto &x:a){
            s+=x;
        }
        mp[s]++;
    }
        
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=words.size();
        int m=words[0].size();
        int total=n*m;
        if(s.size()<total){
            return ans;
        }
        for(int i=0;i<=s.size()-total;i++){
            unordered_map<string,int>mp;
            
            for(int j=0;j<words.size();j++){
                mp[words[j]]++;
            }
            int k;
            for(k=0;k<n;k++){
                
                string temp=s.substr(i+k*m,m);
                if(mp.count(temp)==0){
                    break;
                }
                else{
                    // cout<<temp<<" "<<mp[temp]<<endl;
                    if(mp[temp]!=0){
                        mp[temp]--;
                    }
                    else{
                        // cout<<" "<<temp<<" "<<mp[temp]<<" "<<mp.count(temp)<<endl;
                        break;
                    }
                }
            }
            if(k==n){
                ans.push_back(i);
            }
            
        }
        return ans ;
    }
};