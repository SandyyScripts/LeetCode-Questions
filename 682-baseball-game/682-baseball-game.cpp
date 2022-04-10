class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n=ops.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(ops[i]=="C"){
                st.pop();
            }
            else if(ops[i]=="D"){
                int x=st.top();
                st.push(2*x);
            }
            else if(ops[i]=="+"){
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();
                st.push(x2);
                st.push(x1);
                st.push(x1+x2);
            }
            else{
                string x=ops[i];
                int x1=stoi(x);
                st.push(x1);
            }
        }
        while(st.size()!=0){
            int x=st.top();
            ans+=x;
            st.pop();
        }
        return ans;
    }
};