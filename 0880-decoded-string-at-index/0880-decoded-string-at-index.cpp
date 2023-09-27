class Solution {
public:
    long long cur = 0;
    long long arr[101];
    int dl=0;

    string decodeAtIndex(string s, int k) {
        int l = s.size();
        cur = 0;
        dl = 0;
        string c="";

        for(int i = 0; i < l; i++) { // fill the length array and find the location 'dl'
            if(s[i] >= 'a' && s[i] <= 'z') { // the character is a alphabet
                cur++;
            }
            else if(s[i] >= '2' && s[i] <= '9'){ // the character is a digit
                cur *= s[i]-'0';
            }
            
            arr[i] = cur;

            if(cur >= k){ // break if the current decoded string consists k'th character
                dl=i;
                break;
            }
        }

        if(s[dl] >='a' && s[dl] <= 'z') { // If last character is a alphabet, return it
            c = s[dl];
        }
        else{ // Solve an smaller subproblem
            k %= arr[dl-1];
            if(k==0){
                k = arr[dl-1];
            }
            return decodeAtIndex(s, k);
        }
        
        return c;
    }
};