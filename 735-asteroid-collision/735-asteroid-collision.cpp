class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> ans;
       for(int val:asteroids){
           if(val>0){
               ans.push(val);
           }
           else{
               while(!ans.empty() && ans.top()>0 && ans.top()<-val){
                   ans.pop();
               }
               if(!ans.empty() && ans.top()==-val){
                   ans.pop();
               }
               else if(!ans.empty() && ans.top()>-val){
                   
               }
               else{
                   ans.push(val);
               }
           }
       }
        vector<int> res;
        while(!ans.empty())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};