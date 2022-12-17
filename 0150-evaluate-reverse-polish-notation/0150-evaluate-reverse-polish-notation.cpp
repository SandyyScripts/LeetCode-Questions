class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]== "+" || tokens[i]== "-" || tokens[i]== "*"  || tokens[i]== "/" ){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                long long t;
                if(tokens[i]== "+"){
                    t = a+b;
                }
                else if(tokens[i]== "/" ){
                    t = b/a;
                }
                else if(tokens[i]== "-" ){
                    t = b-a;
                }
                else if(tokens[i]== "*" ){
                    t = a*b;
                }
                st.push(t);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};