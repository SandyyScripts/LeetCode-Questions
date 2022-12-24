class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> arr(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && t[st.top()]<t[i]){
                arr[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return arr;
    }
};