class Solution {
public:
    bool strongPasswordCheckerII(string password) {
         int n = password.length();
        if(n<8)
            return false;
        bool haslo = false, hasup = false,hasdi = false,hassp = false,notgood = false;
        unordered_set<char> hs{'!', '@', '#','$','%','^','&','*','(',')','-','+'};
        for(int i=0;i<n;i++){
            if(islower(password[i])){
                haslo = true;
            }
            else if(isupper(password[i])){
                hasup = true;
            }
            else if(isdigit(password[i])){
                hasdi = true;
            }
            else if(hs.find(password[i]) != hs.end()){
                hassp = true;
            }
            
            if(i>0){
                if(password[i] == password[i-1]){
                    notgood = true;
                    break;
                }
            }
        }
        
        return !notgood && haslo && hasup && hasdi && hassp;
    }
};