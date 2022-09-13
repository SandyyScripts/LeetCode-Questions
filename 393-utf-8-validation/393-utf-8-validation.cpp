class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remb = 0;
        for(auto &x:data){
            if(remb==0){
                
                if(x>>5==0b110) remb=1;
                else if(x>>4==0b1110) remb=2;
                else if(x>>3==0b11110) remb=3;
                else if(x>>7) return false;
                // else return false;
            }
            else{
                if(x>>6==0b10) remb--;
                else return false;
            }
        }
        return remb==0;
    }
};
