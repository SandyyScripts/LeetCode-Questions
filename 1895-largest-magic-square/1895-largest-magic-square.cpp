class Solution {
public:
    bool ispossible(vector<vector<int>>&mat,int s,int e,int sze)
    {
        // d1 : main diagonal
        // d2 : anti diagonal
        int d1=0,d2=0; 
        for(int i=0;i<sze;++i)
        {
            d1+=mat[s+i][e+i];
            d2+=mat[s+i][e+sze-i-1];
        }
        if(d1!=d2) return 0;
        for(int i=0;i<sze;++i)
        {
            int rsum=0,csum=0;
            for(int j=0;j<sze;++j)
            {
                rsum+=mat[s+i][e+j];
                csum+=mat[s+j][e+i];
            }
            if(rsum!=csum || rsum!=d1) return 0;
        }
        return 1;
    }
    
        
    
    int largestMagicSquare(vector<vector<int>>& A) {
        // we start by finding the max possible size of the magic square and check all possible sub matricies 
        // the constraints are small and brute force will pass 
        int minv = min(A.size(),A[0].size());
        for(int k = minv;k>=2;--k)
        {
            for(int i=0;i+k<=A.size();++i)
            {
                for(int j=0;j+k<=A[0].size();++j)
                {
                    if(ispossible(A,i,j,k))
                        return k;
                }
            }
        }
        return 1;
    }
};