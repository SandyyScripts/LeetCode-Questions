class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            if(s[i]=='{'){
                 st.push('{');
            }
            if(s[i]=='['){
                st.push('[');
            }
            if(s[i]==')'){
                if(st.empty() || st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            if(s[i]=='}'){
                 if(st.empty() || st.top()!='{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            if(s[i]==']'){
                if(st.empty() || st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};