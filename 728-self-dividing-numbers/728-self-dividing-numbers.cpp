class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        
        for(int i=left;i<=right;i++){
            int f =0;
            int temp =i;
            while(temp!=0){
                int r= temp%10;
                if(r==0){f=1;break;}
                else if(i%r!=0){f=1;break;}
                temp = temp/10;
            }
            if(f==0)ans.push_back(i);
            
        }
        return ans;
    }
};