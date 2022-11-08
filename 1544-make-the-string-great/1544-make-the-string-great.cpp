class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                char x = st.top();
                // cout<<(char)toupper(x)<<" ";
                if(x!=s[i] && (char)toupper(x)==(char)toupper(s[i])){

                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            char x=st.top();
            st.pop();
            ans+=x;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};