class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char, int>> ss, ts;
        for(int i=0; i<start.size(); i++){
            if(start[i] != '_')ss.push({start[i], i});        
        }
        for(int i=0; i<target.size(); i++){
            if(target[i] != '_')ts.push({target[i], i});
        }
        if(ss.size()!=ts.size()){
            return false;
        }
        while(ss.size()){
            pair<char,int> s,t;
            s=ss.front();
            t=ts.front();
            
            ss.pop();
            ts.pop();
            if(s.first!=t.first) return false;
            if(s.first=='L' && t.second>s.second){
                return false;
            }
            else if(s.first=='R' && t.second<s.second){
                return false;
            }
        }
        return true;
    }
};