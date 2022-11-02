class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        int count=0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                string node = q.front();
                q.pop();
                if(node==end) return count;
                for(char c:"ACGT"){
                    for(int j=0;j<node.size();j++){
                        string cnode = node;
                        cnode[j]=c;
                        if(!visited.count(cnode) && find(bank.begin(),bank.end(),cnode)!=bank.end()){
                            q.push(cnode);
                            visited.insert(cnode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};